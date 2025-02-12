/*!
 * baguetteBox.js
 * @author  feimosi
 * @version 1.3.2
 * @url https://github.com/feimosi/baguetteBox.js
 */
var baguetteBox=function(){function e(e,n){M.transforms=g(),M.svg=p(),t(),X=document.querySelectorAll(e),[].forEach.call(X,function(e){n&&n.filter&&(D=n.filter);var t=e.getElementsByTagName("a");t=[].filter.call(t,function(e){return D.test(e.href)});var i=q.length;q.push(t),q[i].options=n,[].forEach.call(q[i],function(e,t){v(e,"click",function(e){e.preventDefault?e.preventDefault():e.returnValue=!1,o(i),r(t)})})})}function t(){return(w=b("baguetteBox-overlay"))?(C=b("baguetteBox-slider"),E=b("previous-button"),T=b("next-button"),N=b("close-button"),void 0):(w=k("div"),w.id="baguetteBox-overlay",document.getElementsByTagName("body")[0].appendChild(w),C=k("div"),C.id="baguetteBox-slider",w.appendChild(C),E=k("button"),E.id="previous-button",E.innerHTML=M.svg?B:"&lt;",w.appendChild(E),T=k("button"),T.id="next-button",T.innerHTML=M.svg?I:"&gt;",w.appendChild(T),N=k("button"),N.id="close-button",N.innerHTML=M.svg?L:"X",w.appendChild(N),E.className=T.className=N.className="baguetteBox-button",i(),void 0)}function n(e){switch(e.keyCode){case 37:d();break;case 39:c();break;case 27:s()}}function i(){v(w,"click",function(e){e.target&&"IMG"!==e.target.nodeName&&"FIGCAPTION"!==e.target.nodeName&&s()}),v(E,"click",function(e){e.stopPropagation?e.stopPropagation():e.cancelBubble=!0,d()}),v(T,"click",function(e){e.stopPropagation?e.stopPropagation():e.cancelBubble=!0,c()}),v(N,"click",function(e){e.stopPropagation?e.stopPropagation():e.cancelBubble=!0,s()}),v(w,"touchstart",function(e){x=e.changedTouches[0].pageX}),v(w,"touchmove",function(e){j||(e.preventDefault?e.preventDefault():e.returnValue=!1,touch=e.touches[0]||e.changedTouches[0],touch.pageX-x>40?(j=!0,d()):touch.pageX-x<-40&&(j=!0,c()))}),v(w,"touchend",function(){j=!1})}function o(e){if(A!==e){for(A=e,a(q[e].options);C.firstChild;)C.removeChild(C.firstChild);G.length=0;for(var t,n=0;n<q[e].length;n++)t=k("div"),t.className="full-image",t.id="baguette-img-"+n,G.push(t),C.appendChild(G[n])}}function a(e){e||(e={});for(var t in H)P[t]=H[t],"undefined"!=typeof e[t]&&(P[t]=e[t]);C.style.transition=C.style.webkitTransition="fadeIn"===P.animation?"opacity .4s ease":"slideIn"===P.animation?"":"none","auto"===P.buttons&&("ontouchstart"in window||1===q[A].length)&&(P.buttons=!1),E.style.display=T.style.display=P.buttons?"":"none"}function r(e){"block"!==w.style.display&&(v(document,"keydown",n),S=e,l(S,function(){h(S),m(S)}),f(),w.style.display="block",setTimeout(function(){w.className="visible",P.afterShow&&P.afterShow()},50),P.onChange&&P.onChange(S,G.length))}function s(){"none"!==w.style.display&&(y(document,"keydown",n),w.className="",setTimeout(function(){w.style.display="none",P.afterHide&&P.afterHide()},500))}function l(e,t){var n=G[e];if("undefined"!=typeof n){if(n.getElementsByTagName("img")[0])return t&&t(),void 0;imageElement=q[A][e],imageCaption="function"==typeof P.captions?P.captions.call(q[A],imageElement):imageElement.getAttribute("data-caption")||imageElement.title,imageSrc=u(imageElement);var i=k("figure"),o=k("img"),a=k("figcaption");n.appendChild(i),i.innerHTML='<div class="spinner"><div class="double-bounce1"></div><div class="double-bounce2"></div></div>',o.onload=function(){var n=document.querySelector("#baguette-img-"+e+" .spinner");i.removeChild(n),!P.async&&t&&t()},o.setAttribute("src",imageSrc),i.appendChild(o),P.captions&&imageCaption&&(a.innerHTML=imageCaption,i.appendChild(a)),P.async&&t&&t()}}function u(e){var t=imageElement.href;if(e.dataset){var n=[];for(var i in e.dataset)"at-"!==i.substring(0,3)||isNaN(i.substring(3))||(n[i.replace("at-","")]=e.dataset[i]);keys=Object.keys(n).sort(function(e,t){return parseInt(e)<parseInt(t)?-1:1});for(var o=window.innerWidth*window.devicePixelRatio,a=0;a<keys.length-1&&keys[a]<o;)a++;t=n[keys[a]]||t}return t}function c(){var e;return S<=G.length-2?(S++,f(),h(S),e=!0):P.animation&&(C.className="bounce-from-right",setTimeout(function(){C.className=""},400),e=!1),P.onChange&&P.onChange(S,G.length),e}function d(){var e;return S>=1?(S--,f(),m(S),e=!0):P.animation&&(C.className="bounce-from-left",setTimeout(function(){C.className=""},400),e=!1),P.onChange&&P.onChange(S,G.length),e}function f(){var e=100*-S+"%";"fadeIn"===P.animation?(C.style.opacity=0,setTimeout(function(){M.transforms?C.style.transform=C.style.webkitTransform="translate3d("+e+",0,0)":C.style.left=e,C.style.opacity=1},400)):M.transforms?C.style.transform=C.style.webkitTransform="translate3d("+e+",0,0)":C.style.left=e}function g(){var e=k("div");return"undefined"!=typeof e.style.perspective||"undefined"!=typeof e.style.webkitPerspective}function p(){var e=k("div");return e.innerHTML="<svg/>","http://www.w3.org/2000/svg"==(e.firstChild&&e.firstChild.namespaceURI)}function h(e){e-S>=P.preload||l(e+1,function(){h(e+1)})}function m(e){S-e>=P.preload||l(e-1,function(){m(e-1)})}function v(e,t,n){e.addEventListener?e.addEventListener(t,n,!1):e.attachEvent("on"+t,n)}function y(e,t,n){e.removeEventListener?e.removeEventListener(t,n,!1):e.detachEvent("on"+t,n)}function b(e){return document.getElementById(e)}function k(e){return document.createElement(e)}var w,C,E,T,N,x,B='<svg width="44" height="60"><polyline points="30 10 10 30 30 50" stroke="rgba(255,255,255,0.5)" stroke-width="4"stroke-linecap="butt" fill="none" stroke-linejoin="round"/></svg>',I='<svg width="44" height="60"><polyline points="14 10 34 30 14 50" stroke="rgba(255,255,255,0.5)" stroke-width="4"stroke-linecap="butt" fill="none" stroke-linejoin="round"/></svg>',L='<svg width="30" height="30"><g stroke="rgb(160, 160, 160)" stroke-width="4"><line x1="5" y1="5" x2="25" y2="25"/><line x1="5" y1="25" x2="25" y2="5"/></g></svg>',P={},H={captions:!0,buttons:"auto",async:!1,preload:2,animation:"slideIn",afterShow:null,afterHide:null,onChange:null},M={},S=0,A=-1,j=!1,D=/.+\.(gif|jpe?g|png|webp)/i,X=[],q=[],G=[];return[].forEach||(Array.prototype.forEach=function(e,t){for(var n=0;n<this.length;n++)e.call(t,this[n],n,this)}),[].filter||(Array.prototype.filter=function(e,t,n,i,o){for(n=this,i=[],o=0;o<n.length;o++)e.call(t,n[o],o,n)&&i.push(n[o]);return i}),{run:e,showNext:c,showPrevious:d}}();

/*	Citations Script
*	Copyright 2015 Sharpened Productions
*/

jQuery.fn.selectText = function(){
    var doc = document
        , element = this[0]
        , range, selection
    ;
    if (doc.body.createTextRange) {
        range = document.body.createTextRange();
        range.moveToElementText(element);
        range.select();
    } else if (window.getSelection) {
        selection = window.getSelection();        
        range = document.createRange();
        range.selectNodeContents(element);
        selection.removeAllRanges();
        selection.addRange(range);
    }
};

$(document).ready(function() {
	var citems = ['apa', 'mla', 'chicago', 'html', 'link'];
	var csel= null;
	var cHasSelectedText = false;
	$('#'+citems[0]+',#'+citems[1]+',#'+citems[2]+',#'+citems[3]+',#'+citems[4]).click(function(event){
		event.preventDefault();
		document.getSelection().removeAllRanges(); // deselect all text
		cHasSelectedText = false;
		var id = $(this).attr('id');
		if(csel == id) {
			$(this).removeClass('csel');
			$('.citation').css('display', 'none');
			csel = null;
			$('.citation').html('');
		} else {
			csel = id;
			for(var i=0; i<citems.length; i++) {
				if(citems[i] == id) {
					$('#'+citems[i]).addClass('csel');
				} else {
					$('#'+citems[i]).removeClass('csel');
				}
			}
			$.post("/cs", { t:cterm, c:id, u:curl }, function(data) {
				$('.citation').html(data);
				$('.citation').css('display', 'block');
				$('.citation').select();
			});
		}
	});
	$('.citation').click(function() {
		if(!cHasSelectedText) {
			cHasSelectedText = true;
			$('.citation').selectText();
		}
	});
	baguetteBox.run('.baguetteBox', {
        captions: function(element) {
            // `this` == Array of current gallery items
            return element.getElementsByTagName('img')[0].alt;
        }
    });
});