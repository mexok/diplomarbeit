/**
 * @license Copyright (c) 2003-2015, CKSource - Frederico Knabben. All rights reserved.
 * For licensing, see LICENSE.md or http://ckeditor.com/license
 */

CKEDITOR.editorConfig = function( config ) {
	// Define changes to default configuration here.
	// For complete reference see:
	// http://docs.ckeditor.com/#!/api/CKEDITOR.config

	// The toolbar groups arrangement, optimized for a single toolbar row.
	config.toolbarGroups = [
		{ name: 'document',	   groups: [ 'mode', 'document', 'doctools' ] },
		{ name: 'clipboard',   groups: [ 'clipboard', 'undo' ] },
		{ name: 'editing',     groups: [ 'find', 'selection', 'spellchecker' ] },
		{ name: 'forms' },
		{ name: 'basicstyles', groups: [ 'basicstyles', 'cleanup' ] },
		{ name: 'paragraph',   groups: [ 'list', 'indent', 'blocks', 'align', 'bidi' ] },
		{ name: 'links' },
		{ name: 'insert' },
		{ name: 'styles' },
		{ name: 'colors' },
		{ name: 'tools' },
		{ name: 'others' },
		{ name: 'about' }
	];



	// Dialog windows are also simplified.
	config.removeDialogTabs = 'link:advanced';
	
	config.toolbar_comment = [
		{ name: 'basicstyles', items: [ 'Bold', 'Italic','Smileys' ] },
		{ name: 'paragraph', items: [ 'NumberedList', 'BulletedList', '-', 'Outdent', 'Indent','Smiley' ] },
		{ name: 'links', items: [ 'Link', 'Unlink' ] },
	];
	
	config.removeButtons = 'Cut,Copy,Paste,Undo,Redo,Anchor,Strike,Subscript,Superscript,Indent,Outdent,About';
	
	config.enterMode = CKEDITOR.ENTER_BR;
	config.extraPlugins = 'contextmenu,smiley,commentSuggest,htmlwriter,wordcount,autolink';
	
	config.wordcount = {

	    // Whether or not you want to show the Paragraphs Count
	    showParagraphs: false,

	    // Whether or not you want to show the Word Count
	    showWordCount: false,

	    // Whether or not you want to show the Char Count
	    showCharCount: true,

	    // Whether or not you want to count Spaces as Chars
	    countSpacesAsChars: true,

	    // Whether or not to include Html chars in the Char Count
	    countHTML: false,
	    
	    // Maximum allowed Word Count, -1 is default for unlimited
	    maxWordCount: -1,

	    // Maximum allowed Char Count, -1 is default for unlimited
	    maxCharCount: -1
	};
};
