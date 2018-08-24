using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

using ImpsEngine;
using OpenTK.Graphics.ES20;

namespace YamlGuiWPF
{
    /// <summary>
    /// Interaktionslogik für MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private bool isCreated = false;

        private readonly object nativeCodeLock = new object();

        public MainWindow()
        {
            InitializeComponent();
        }

        private void OpenGLView_Resized(object sender, EventArgs e)
        {
        }

        private void OpenGLView_Initialized(object sender, EventArgs e)
        {
        }

        private void OpenGLView_Draw(object sender, EventArgs e)
        {
            if (isCreated == false)
            {
                isCreated = true;

                var bitmapMappings = IABitmap.GetBitmapMappings();
                SetOpenGLWinMappings(bitmapMappings);

                PresentationSource _presentationSource = PresentationSource.FromVisual(Application.Current.MainWindow);
                Matrix matix = _presentationSource.CompositionTarget.TransformToDevice;
                Size s = new Size(SystemParameters.PrimaryScreenWidth * matix.M11, SystemParameters.PrimaryScreenHeight * matix.M22);
                int WidthOfScreen = (int)SystemParameters.PrimaryScreenWidth;
                int HeightOfScreen = (int)SystemParameters.PrimaryScreenHeight;
                CreateResources((int)s.Width, (int)s.Height, (int)SystemParameters.PrimaryScreenWidth, (int)SystemParameters.PrimaryScreenHeight);
            }
            GL.Clear(ClearBufferMask.ColorBufferBit | ClearBufferMask.DepthBufferBit);
            Render();
        }

        [DllImport("CSrc.dll", EntryPoint = "setOpenGLWinMappings", CallingConvention = CallingConvention.Cdecl)]
        public static extern void SetOpenGLWinMappings(IABitmap.IABitmapMappings mappings);

        [DllImport("CSrc.dll", EntryPoint = "createResources", CallingConvention = CallingConvention.Cdecl)]
        public static extern void CreateResources(int realWidthOfScreen, int realHeightOfScreen, int frameBufferWidth, int frameBufferHeight);

        [DllImport("CSrc.dll", EntryPoint = "render", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Render();
    }
}