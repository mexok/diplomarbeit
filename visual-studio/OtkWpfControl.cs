using System;
using System.Collections.Generic;
using System.Linq;
using System.ComponentModel;
using System.Diagnostics;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Imaging;

using OpenTK;
using OpenTK.Graphics;

namespace OpenTK.WPF
{
    using FramebufferAttachment = OpenTK.Graphics.OpenGL.FramebufferAttachment;
    using FramebufferErrorCode = OpenTK.Graphics.OpenGL.FramebufferErrorCode;
    using FramebufferTarget = OpenTK.Graphics.OpenGL.FramebufferTarget;
    using GL = OpenTK.Graphics.OpenGL.GL;
    using PixelFormat = OpenTK.Graphics.OpenGL.PixelFormat;
    using PixelType = OpenTK.Graphics.OpenGL.PixelType;
    using RenderbufferStorage = OpenTK.Graphics.OpenGL.RenderbufferStorage;
    using RenderbufferTarget = OpenTK.Graphics.OpenGL.RenderbufferTarget;

    public class OtkWpfControl : UserControl
    {
        #region Dependency Properties
        
        #region VersionMajor

        private static readonly DependencyProperty VersionMajorProperty = DependencyProperty.Register
        (
            "VersionMajor",
            typeof(int),
            typeof(OtkWpfControl),
            new PropertyMetadata(2)
        );

        public int VersionMajor
        {
            get { return (int)GetValue(VersionMajorProperty); }
            set { SetValue(VersionMajorProperty, value); }
        }

        #endregion VersionMajor

        #region VersionMinor
        
        private static readonly DependencyProperty VersionMinorProperty = DependencyProperty.Register
        (
            "VersionMinor",
            typeof(int),
            typeof(OtkWpfControl),
            new PropertyMetadata(0)
        );

        public int VersionMinor
        {
            get { return (int)GetValue(VersionMinorProperty); }
            set { SetValue(VersionMinorProperty, value); }
        }

        #endregion VersionMinor

        #endregion Dependency Properties

        #region Events

        [Description("Called when OpenGL has been initialized."), Category("SharpGL")]
        public event EventHandler OpenGLInitialized;

        [Description("Called when the control is resized - you can use this to do custom viewport projections."), Category("SharpGL")]
        public event EventHandler Resized;

        [Description("Called whenever OpenGL drawing can should occur."), Category("SharpGL")]
        public event EventHandler OpenGLDraw;
        

        #endregion Events

        public OtkWpfControl()
        {
            Content = mImage;

            Loaded += OpenGLControl_Loaded;
            Unloaded += OpenGLControl_Unloaded;
        }
        
        public override void OnApplyTemplate()
        {
            //  Call the base.
            base.OnApplyTemplate();

            // initialize framebufferhandler for OpenTK
            mLoaded = false;
            mSize = Size.Empty;
            mFramebufferId = -1;

            var gmode = new GraphicsMode(DisplayDevice.Default.BitsPerPixel, 16, 0, 4, 0, 2, false);
            mTkGlControl = new GLControl(gmode, VersionMajor, VersionMinor, GraphicsContextFlags.Default);
            mTkGlControl.MakeCurrent();

            //  Fire the OpenGL initialised event.
            OpenGLInitialized?.Invoke(this, EventArgs.Empty);
        }

        #region Implementation

        #region Event Handlers

        private void OpenGLControl_Loaded(object sender, RoutedEventArgs routedEventArgs)
        {
            SizeChanged += OpenGLControl_SizeChanged;

            UpdateOpenGLControl(RenderSize);

            // start rendering to be on WPF redering timing
            CompositionTarget.Rendering += CompositionTarget_Rendering;
        }

        private void OpenGLControl_Unloaded(object sender, RoutedEventArgs routedEventArgs)
        {
            SizeChanged -= OpenGLControl_SizeChanged;
            CompositionTarget.Rendering -= CompositionTarget_Rendering;
        }

        private void OpenGLControl_SizeChanged(object sender, SizeChangedEventArgs e)
        {
            UpdateOpenGLControl(e.NewSize);
        }

        public static bool ShouldRender = true;

        private void CompositionTarget_Rendering(object sender, EventArgs e)
        {
            if (ShouldRender)
            {
                // https://evanl.wordpress.com/2009/12/06/efficient-optimal-per-frame-eventing-in-wpf/
                // import from FrameBufferHandler
                if (GraphicsContext.CurrentContext != mTkGlControl.Context)
                {
                    mTkGlControl.MakeCurrent();
                }

                var framebuffersize = new Size(ActualWidth, ActualHeight);
                if (framebuffersize != mSize || mLoaded == false)
                {
                    mSize = framebuffersize;
                    CreateFramebuffer();
                }

                int imageSizeWidth = (int)Math.Ceiling(mSize.Width);
                int imageSizeHeight = (int)Math.Ceiling(mSize.Height);

                // all of drawing commands will be performed onto the FBO
                GL.BindFramebuffer(FramebufferTarget.Framebuffer, mFramebufferId);

                //	If there is a draw handler, then call it.
                Debug.Assert(OpenGLDraw != null);
                OpenGLDraw?.Invoke(this, EventArgs.Empty);

                // wait FBO has completed drawing
                GL.Finish();

                if (mDrawnImage == null || mDrawnImage.Width != imageSizeWidth || mDrawnImage.Height != imageSizeHeight)
                {
                    // create bitmap for imagesource to be displayed
                    mDrawnImage = new WriteableBitmap(imageSizeWidth, imageSizeHeight, 96, 96, PixelFormats.Pbgra32, BitmapPalettes.WebPalette);

                    // (re)assign read buffer
                    mBackbuffer = new byte[imageSizeWidth * imageSizeHeight * 4];
                }

                // to avoid image upside down, read to another memory
                GL.ReadPixels(0, 0, imageSizeWidth, imageSizeHeight, PixelFormat.Bgra, PixelType.UnsignedByte, mBackbuffer);

                // WriteableBitmap should be locked as short as possible
                mDrawnImage.Lock();

                // copy pixels upside down
                var src = new Int32Rect(0, 0, (int)mDrawnImage.Width, 1);
                for (int y = 0; y < (int)mDrawnImage.Height; y++)
                {
                    src.Y = (int)mDrawnImage.Height - y - 1;
                    mDrawnImage.WritePixels(src, mBackbuffer, mDrawnImage.BackBufferStride, 0, y);
                }
                mDrawnImage.AddDirtyRect(new Int32Rect(0, 0, (int)mDrawnImage.Width, (int)mDrawnImage.Height));

                mDrawnImage.Unlock();

                if (mBackbuffer != null)
                {
                    // refresh displayed image
                    mImage.Source = mDrawnImage;
                }
            }
        }

        #endregion Event Handlers

        /// <summary>
        /// tell handler control being resized
        /// </summary>
        /// <param name="width">The width of the OpenGL drawing area.</param>
        /// <param name="height">The height of the OpenGL drawing area.</param>
        private void UpdateOpenGLControl(Size framebuffersize)
        {
            Resized?.Invoke(this, EventArgs.Empty);
        }

        /// <summary>
        /// create FBO for offscreen derndering using a render buffer
        /// </summary>
        private void CreateFramebuffer()
        {
            mTkGlControl.MakeCurrent();

            if (mFramebufferId > 0)
            {
                GL.DeleteFramebuffer(mFramebufferId);
            }

            if (mColorbufferId > 0)
            {
                GL.DeleteRenderbuffer(mColorbufferId);
            }

            if (mDepthbufferId > 0)
            {
                GL.DeleteRenderbuffer(mDepthbufferId);
            }

            mFramebufferId = GL.GenFramebuffer();
            GL.BindFramebuffer(FramebufferTarget.Framebuffer, mFramebufferId);

            mColorbufferId = GL.GenRenderbuffer();
            GL.BindRenderbuffer(RenderbufferTarget.Renderbuffer, mColorbufferId);
            GL.RenderbufferStorage(RenderbufferTarget.Renderbuffer, RenderbufferStorage.Rgba8, (int)mSize.Width, (int)mSize.Height);

            mDepthbufferId = GL.GenRenderbuffer();
            GL.BindRenderbuffer(RenderbufferTarget.Renderbuffer, mDepthbufferId);
            GL.RenderbufferStorage(RenderbufferTarget.Renderbuffer, RenderbufferStorage.DepthComponent24, (int)mSize.Width, (int)mSize.Height);

            GL.FramebufferRenderbuffer(FramebufferTarget.Framebuffer, FramebufferAttachment.ColorAttachment0, RenderbufferTarget.Renderbuffer, mColorbufferId);
            GL.FramebufferRenderbuffer(FramebufferTarget.Framebuffer, FramebufferAttachment.DepthAttachment, RenderbufferTarget.Renderbuffer, mDepthbufferId);

            var error = GL.CheckFramebufferStatus(FramebufferTarget.Framebuffer);
            if (error != FramebufferErrorCode.FramebufferComplete)
            {
                throw new Exception("Failed to create FrameBuffer for OpenGLControl");
            }

            mLoaded = true;
        }

        #endregion Implementation

        #region Fields

        private Image mImage = new Image();

        private GLControl mTkGlControl;         // hidden WinForms control for offscreen rendering

        private byte[] mBackbuffer;             // FBO pixels read buffer , create statically to avoid GC
        private WriteableBitmap mDrawnImage;    // displaying bitmap
        private int mFramebufferId;             // FBO
        private int mColorbufferId;             // FBO pixel buffer
        private int mDepthbufferId;             // FBO depth buffer
        private Size mSize;                     // FBO (drawing) size
        private bool mLoaded;

        #endregion Fields
    }
}
