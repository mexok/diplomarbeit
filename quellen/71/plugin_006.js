CKEDITOR.plugins.add('commentSuggest',
				{
					init : function(editor) {
						
						 var autocompleteCommand = editor.addCommand('autocomplete', {
							exec : function(editor) {
                                                                
								var dummyElement = editor.document
										.createElement('span');
								editor.insertElement(dummyElement);

								var x = 0;
								var y = 0;

								var obj = dummyElement.$;

								while (obj.offsetParent) {
									x += obj.offsetLeft;
									y += obj.offsetTop;
									obj = obj.offsetParent;
								}
								x += obj.offsetLeft;
								y += obj.offsetTop;

								dummyElement.remove();

								editor.contextMenu.show(editor.document
										.getBody(), null, x, y);
							}
						});
					},

					afterInit : function(editor) {

                        editor.on('contentDom', function(e) {
                            var editable = editor.editable();
                            
                            editable.attachListener(editable, 'keypress', function(evt) {
 
                               var typed_char = String.fromCharCode(evt.data.$.which);

                               if (typed_char === '@' ) {                                   
                                   
                                    editor.execCommand('autocomplete');
                                }
                            });
                        });
                                                
						
						var firstExecution = true;
						var dataElement = {};
						
						 editor.addCommand('reloadSuggestionBox', {
								exec : function(editor,suggestions) {
                                                                    
									if (editor.contextMenu) {
										dataElement = {};
										editor.addMenuGroup('suggestionBoxGroup');
										$.each(suggestions,function(i, suggestion) {
															var suggestionBoxItem = "suggestionBoxItem"+ i; 
															dataElement[suggestionBoxItem] = CKEDITOR.TRISTATE_OFF;
															editor.addMenuItem(suggestionBoxItem,
														{
															id : suggestion.useruuid,
															label : suggestion.username,
															link :  suggestion.userlink,
															group : 'suggestionBoxGroup',
															icon  : null,
															onClick : function() {

																if(this.link != null && this.link.length > 0){
																	
																	var html = '<a target="_blank" class="mention" rel="'+this.id+'" href="'+ this.link +'" title="'+this.label+'">' +this.label +'</a>';

																	var newElement = CKEDITOR.dom.element.createFromHtml( html, editor.document );
																	editor.insertElement( newElement );																	
}else{

var html = '<span>'+this.label +'</span>';

var newElement = CKEDITOR.dom.element.createFromHtml( html, editor.document );
editor.insertElement( newElement );
}			
															},
														});
															});

										if(firstExecution == true)
											{
												editor.contextMenu.addListener(function(element) {
													return dataElement;
												});
											firstExecution = false;
											}
									}
								}
						 });
						
						delete editor._.menuItems.paste;
					},
				});

