var language;
var url;

/**
 * BAm - Einfach diese Funktion aufrufen, um Socialbar neu zu erzeugen. mit aktueller URL!
 * 
 * @param 
 * @returns eine ganze Bar
 */
function createSocialBar(layout,links,privacy,sharecounts,sharetxts,urlfix,id)
{
	language = getMeta("language");
	
	url = getURL();

	var url_prefix = "/shared/vogelonline/img/socialmedia";
	var options = {
		'gplus' : {
			'name' : 'Google+',
			'dummy_url' : url_prefix + '/dummy_gplus_' + language + '.png'
		},
		'facebook' : {
			'name' : 'Facebook',
			'dummy_url' : url_prefix + '/dummy_facebook_' + language + '.png'
		},
		'facebooklike' : {
			'name' : 'Facebook',
			'dummy_url' : url_prefix + '/dummy_facebook_' + language + '.png'
		},
		'twitter' : {
			'name' : 'Twitter',
			'dummy_url' : url_prefix + '/dummy_twitter_' + language + '.png'
		},
		'xing' : {
			'name' : 'Xing',
			'dummy_url' : url_prefix + '/dummy_xing_' + language + '.png'
		},
		'linkedin' : {
			'name' : 'LinkedIn',
			'dummy_url' : url_prefix + '/dummy_linkedin_' + language + '.png'
		}
	};
	
	if(typeof id != "undefined"){
		var areaElements = $( "#"+id+" .socialmedia_privacy_area");	
	}
	else
	{		
		var areaElements = $( ".socialmedia_privacy_area");
	}

	// Die vorhandenen Privacy_Areas durchgehen
	for ( var i_el = 0; i_el < areaElements.length; i_el++) {
		areaElement = areaElements[i_el];
		
		classname = $(areaElement).attr("class");
		//privacy = classname.search(" privacy");
		if (privacy == 0) {
			privacy = false;
		} else {
			privacy = true;
		}

		childelements = $(areaElement).children();
		
		// Die einzelnen Elemente in der Privacy-Area durchgehen
		for ( var i = 0; i < childelements.length; i++) {
			element = childelements[i];
			// Informationen in die Infobox
			if (element.id == "socialprivacy_infobox" && privacy && layout == 'common') {
				element.innerHTML = '<img id="socialprivate_' + '"' + 'alt="'
						+ 'Info"' + 'src="' + url_prefix
						+ '/socialprivacy_info.png'
						+ '" style="cursor:pointer"'
						+ '">' + '<div class="info">' + getPrivacyInfo()
						+ '</div>';

				childElement = element.getElementsByTagName("img")[0];
				if (childElement.addEventListener) {
					childElement.addEventListener("mouseover", showinfo);
					childElement.addEventListener("mouseout", hideinfo);
					childElement.addEventListener("click", openprivacyinfos);

				} else {
					childElement.attachEvent("onmouseover", showinfo);
					childElement.attachEvent("onmouseout", hideinfo);
					childElement.attachEvent("onclick", openprivacyinfos);
				}
			// Deaktivierte Buttons anzeigen
			} else if (element && privacy && layout == 'common') {
				network = options[element.id];
				element.innerHTML = '<img id="socialprivate_' + element.id
						+ '"' + 'alt="' + network.name + '-Dummy"' + 'src="'
						+ network.dummy_url + '" style="cursor:pointer"'

						+ '">' + '<div class="info">'
						+ getInfotext(network.name) + '</div>';

				childElement = element.getElementsByTagName("img")[0];
				if (childElement.addEventListener) {
					childElement.addEventListener("mouseover", showinfo);
					childElement.addEventListener("mouseout", hideinfo);
					childElement.addEventListener("click", activate);

				} else {
					childElement.attachEvent("onmouseover", showinfo);
					childElement.attachEvent("onmouseout", hideinfo);
					childElement.attachEvent("onclick", activate);
				}
			// Aktivierte Buttons anzeigen
			} else {

				code = getInnerHtml("socialprivate_" + element.id,layout,links,sharecounts,sharetxts,urlfix,areaElements);
				$(element).html(code);

			}
		}

	}
}

/**
 * Rückgabe des Meta-Werts mit dem übergebenen Namen
 * 
 * @param name
 * @returns metaContent
 */
function getMeta(name) {
	var content = $('meta[name="' + name + '"]').attr('content');
	return content || '';
}

/**
 * Rückgabe des Dokument-Titels.
 * 
 * @returns title
 */
function getTitle() {

	title = $('title').first().text();
	if (!title) {
		title = document.title;
	}
	return encodeURIComponent(title);
}

/**
 * 
 * @param response
 */
function saveshorturl(response) {
	if (!response.id) {
		response = eval("(" + response + ")");
	}
	shorturl = response.id;

}
/**
 * Anzeigen des Info-Elements
 * 
 * @param event
 */
function showinfo(event) {
	caller = event.srcElement;
	if (!caller) {
		caller = this;
	}
	if ($('.artikel').length > 0) {
		$('.artikel').css('overflow', 'visible');
	}

	$(caller).siblings().show();
}

/**
 * Ausblenden des Infoelements
 * 
 * @param event
 */
function hideinfo(event) {
	caller = event.srcElement;
	if (!caller) {
		caller = this;
	}
	if ($('.artikel').length > 0) {
		$('.artikel').css('overflow', 'hidden');
	}

	$(caller).siblings().hide();
}

function openprivacyinfos(event) {
	if (language == "de") {
		url = "/datenschutz"
	} else if (language == "en") {
		url = "/privacy"
	} else if (language == "fr") {
		url = "/privacy"
	}

	window.open(url);
}

/**
 * Rückgabe des Infotextes mit eingebautem Anbieter-Namen.
 * 
 * @param name
 * @returns
 */
function getInfotext(name) {

	if (language == "de") {
		var infotext = "Klicken Sie hier, um den "
				+ name
				+ " - Button zu aktivieren. Schon beim Aktivieren werden Daten an Dritte &uuml;bertragen. Mehr Infos unter i";
	} else if (language == "en") {
		var infotext = "Click here to activate the " + name
				+ "- button. Personal infos are submitted, when activating."
	} else if (language == "fr") {
		var infotext = "Cliquez ici pour activer le bouton de "
				+ name
				+ ". En activant le bouton vous transmisez des données à des tiers. Plus d'informations quand (i)"
	}

	return infotext;
}

function getPrivacyInfo() {

	if (language == "de") {
		var infotext = "Zum Schutz Ihrer Privatsphäre sind unsere Social-Media-Buttons standardmäßig deaktiviert. Sie können sie einfach mit einem Klick auf den jeweiligen Button aktivieren. Hierbei werden Daten an den jeweiligen Anbieter übertragen, bitte beachten Sie dazu die Informationen in unserer Datenschutzbestimmung.";
	} else if (language == "en") {
		var infotext = "Social Buttons are disabled by default to protect your privacy. To activate a button, simple click. More information are stored at our Privacy Notice.";
	} else if (language == "fr") {
		var infotext = "Pour la protection de votre vie privée, nos boutons des médias sociaux sont désactivés par défaut. Vous pouvez les activer en cliquant sur le bouton approprié. Vos données sont transférées aux fournisseurs correspondants. S'il vous plaît faites attention aux informations dans notre déclaration de confidentialité.";
	}

	return infotext;

}

/**
 * URL anhand des "canonical"-Headers oder der realen URL zurückgeben.
 */
function getURL() {
	var url = getOriginalUrl();
	var canonical = $("link[rel=canonical]").attr("href");

	if (canonical && canonical.length > 0) {
		if (canonical.indexOf("http") < 0) {
			canonical = document.location.protocol + "//"
					+ document.location.host + canonical;
		}
		url = canonical;
	}
	
	var req = url.search(/\?/);
	
	if (req < 0) {
		url = url + "?cmp="
	} else {
		url = url + "&cmp="
	}

	return url;
}

function getOriginalUrl() {
	var url = document.location.href;
	
	var req = url.search(/\index.\.html/);
	
	if (req > 0) {
		url = url.substr(0,req);
	}
	return url;
}

function getDescription(portal) {
	if (language == "de") {
		var infotext = "Artikel teilen auf " & portal;
	} else if (language == "en") {
		var infotext = "Artikel teilen auf " & portal;
	} else if (language == "fr") {
		var infotext = "Artikel teilen auf " & portal;
	}
	return infotext;
}

// SiteCatalyst-Tracking
function getUrlWithTrackingCode(url,trackingcode,trackingcode_ga) {
	var req = url.search(/\?/);

	if (req < 0) {
		url = url + "?cmp=" + trackingcode;
		url = url + trackingcode_ga;
	} else {
		url = url + "&cmp=" + trackingcode;
		url = url + trackingcode_ga;
	}
	
	return url;
}

/*
 * Code für Social Plugin anhand der übergebenen ID aus der entsprechenden
 * Funktion zurückgeben.
 */
function getInnerHtml(elementId,layout,links,sharecounts,sharetxts,urlfix,areaElements) {
	if (elementId == "socialprivate_facebook") {
		code = getFacebook(layout,links,sharecounts['facebook'],sharetxts['facebook'],urlfix);
	} else if (elementId == "socialprivate_facebooklike") {
		code = getFacebooklike(layout,links,sharecounts['facebooklike'],sharetxts['facebooklike'],urlfix);
	} else if (elementId == "socialprivate_twitter") {
		code = getTwitter(layout,links,sharecounts['twitter'],sharetxts['twitter'],urlfix);
	} else if (elementId == "socialprivate_gplus") {
		code = getGoogleplus(layout,links,sharecounts['googleplus'],sharetxts['googleplus'],urlfix);
	} else if (elementId == "socialprivate_xing") {
		code = getXing(layout,links,sharecounts['xing'],sharetxts['xing'],urlfix);
	} else if (elementId == "socialprivate_linkedin") {
		code = getLinkedIn(layout,links,sharecounts['linkedin'],sharetxts['linkedin'],urlfix);
	} else if (elementId == "socialprivate_whatsapp") {
		code = getWhatsapp(layout,links,sharecounts['whatsapp'],sharetxts['whatsapp'],urlfix,areaElements);
	} else {
		code = "NULL";
	}

	return code;
}

//
// Link im Popup oder neues Fenster
//
$(document).on("click","button[data-social-loader~=popup]",function(a){
	a.preventDefault();
	window.open($(this).attr("data-social-url"),"","toolbar=no, width=650, height=450");
});
$(document).on("click","button[data-social-loader~=blank]",function(a){
	a.preventDefault();
	window.open($(this).attr("data-social-url"), '_blank');
});

//
// Facebook teilen
//
function getFacebook(layout,links,count,text,urlfix) {
	
	// Tracking: SiteCatalyst + Google Analytics
	var url = getUrlWithTrackingCode(urlfix,'sm-fb-swyn','&utm_source=facebook&utm_medium=sm&utm_campaign=facebook-swyn');
	
	if (language == "de") {
		fb_language = "de_DE";
	} else if (language == "fr") {
		fb_language = "fr_FR";
	} else {
		fb_language = "en_US";
	}
	
	var title = getTitle();

	var fb_enc_uri = '//www.facebook.com/share.php?u=' + encodeURIComponent(url) + '&title=' + title;
	
	if(layout == 'custom')
	{
		var code = '<a class="fb" href="' + fb_enc_uri + '" ';
		if (links == 'popup') {
			code += 'data-social-loader="popup"';
		} else {
			code += 'data-social-loader="blank"';
		}
		code += '>' +
			'<img ';
		if (language == "de") {
			code += 'title="Artikel teilen auf Facebook"';
		} else if (language == "en") {
			code += 'title="share article on Facebook"';
		} else if (language == "fr") {
			code += 'title="Partagez cet article sur Facebook"';
		}
		code += 'src="/shared/vogelonline/img/bep30/smbutton/facebook.png">' +
			'</a>';
	}
	else if(layout == 'responsive')
	{
		var code = '<button class="fb" data-social-url="' + fb_enc_uri + '" ';
		if (links == 'popup') {
			code += 'data-social-loader="popup"';
		} else {
			code += 'data-social-loader="blank"';
		}
		code += '>' +
			'<img ';
		if (language == "de") {
			code += 'title="Artikel teilen auf Facebook"';
		} else if (language == "en") {
			code += 'title="share article on Facebook"';
		} else if (language == "fr") {
			code += 'title="Partagez cet article sur Facebook"';
		}
		code += 'src="/shared/vogelonline/img/bep30/smbutton/facebook_128.svg"><span>' + count + '</span><span class="sm-text">' + text + '</span></button>';
	}
	else
	{
		var code = '<div class="fb-share-button" data-href="' + url + '" data-layout="button_count"></div>';
	}

	return code;
}

//
//Facebook like
//
function getFacebooklike(layout,links,count,text,urlfix) {
	
	// Tracking: SiteCatalyst + Google Analytics
	var url = getUrlWithTrackingCode(urlfix,'sm-fb-swyn','&utm_source=facebook&utm_medium=sm&utm_campaign=facebook-swyn');
	
	if (language == "de") {
		fb_language = "de_DE";
	} else if (language == "fr") {
		fb_language = "fr_FR";
	} else {
		fb_language = "en_US";
	}
	
	var title = getTitle();

	var fb_enc_uri = url;
	fb_enc_uri = '//www.facebook.com/plugins/like.php?href=' + encodeURIComponent(url);

	if(layout == 'custom')
	{
		var code = '<a class="fb" href="' + fb_enc_uri + '" ';
		if (links == 'popup') {
			code += 'data-social-loader="popup"';
		} else {
			code += 'data-social-loader="blank"';
		}
		code += '>' +
			'<img ';
		if (language == "de") {
			code += 'title="Gefällt mir"';
		} else if (language == "en") {
			code += 'title="like article"';
		} else if (language == "fr") {
			code += 'title="like article"';
		}
		code += 'src="/shared/vogelonline/img/bep30/smbutton/fb_like.png">' +
			'</a>';
	}
	else if(layout == 'responsive')
	{
		var code = '<button class="fb" data-social-url="' + fb_enc_uri + '" ';
		if (links == 'popup') {
			code += 'data-social-loader="popup"';
		} else {
			code += 'data-social-loader="blank"';
		}
		code += '>' +
			'<img ';
		if (language == "de") {
			code += 'title="Gefällt mir"';
		} else if (language == "en") {
			code += 'title="like article"';
		} else if (language == "fr") {
			code += 'title="like article"';
		}
		code += 'src="/shared/vogelonline/img/bep30/smbutton/fb_like_128.png"><span>' + count + '</span><span class="sm-text">' + text + '</span></button>';
	}
	else
	{
		var code = '<div class="fb-like" data-href="' + fb_enc_uri + '" data-layout="button_count" data-action="like" data-show-faces="false" data-share="false"></div>';
	}

	return code;
}

//
// Twitter
//
function getTwitter(layout,links,count,text,urlfix) {
	
	var url = urlfix.replace('?cmp=sm-tw-swyn','');
	
	// Tracking: SiteCatalyst + Google Analytics
	var urltrack = getUrlWithTrackingCode(url,'sm-tw-swyn','&utm_source=twitter&utm_medium=sm&utm_campaign=twitter-swyn');
	
	var tw_enc_uri = encodeURIComponent(urltrack);
	
	var title = getTitle();
	
	if(layout == 'custom')
	{
		var code = '<a class="tw" href="https://twitter.com/share?url=' + tw_enc_uri + '&text=' + title + '" ';
		if (links == 'popup') {
			code += 'data-social-loader="popup"';
		} else {
			code += 'data-social-loader="blank"';
		}
		code += '>' +
			'<img ';
		if (language == "de") {
			code += 'title="Artikel teilen auf Twitter"';
		} else if (language == "en") {
			code += 'title="share article on Twitter"';
		} else if (language == "fr") {
			code += 'title="Partagez cet article sur Twitter"';
		}
		code += 'src="/shared/vogelonline/img/bep30/smbutton/twitter.png">' +
		'</a>';
	}
	else if(layout == 'responsive')
	{
		var code = '<button class="tw" data-social-url="https://twitter.com/share?url=' + tw_enc_uri + '&text=' + title + '" ';
		if (links == 'popup') {
			code += 'data-social-loader="popup"';
		} else {
			code += 'data-social-loader="blank"';
		}
		code += '>' +
			'<img ';
		if (language == "de") {
			code += 'title="Artikel teilen auf Twitter"';
		} else if (language == "en") {
			code += 'title="share article on Twitter"';
		} else if (language == "fr") {
			code += 'title="Partagez cet article sur Twitter"';
		}
		code += 'src="/shared/vogelonline/img/bep30/smbutton/twitter_128.svg"><span>' + count + '</span><span class="sm-text">' + text + '</span></button>';
	}
	else
	{
		var code = '<iframe allowtransparency="true" frameborder="0" scrolling="no" src="//platform.twitter.com/widgets/tweet_button.html?url='
			+ tw_enc_uri
			+ '&amp;original_referer='
			+ encodeURIComponent(url)
			+ '&amp;lang='
			+ language
			+ '&amp;text='
			+ title
			+ '&amp;count=horizontal&amp" style="width:130px; height:25px;"></iframe>';
	}
	
	return code;
}

//
// Google+
//
function getGoogleplus(layout,links,count,text,urlfix) {
	
	// Tracking: SiteCatalyst + Google Analytics
	var url = getUrlWithTrackingCode(urlfix,'sm-g-swyn','&utm_source=gplus&utm_medium=sm&utm_campaign=gplus-swyn');
	
	if(layout == 'custom')
	{
		var code = '<a class="gp" href="https://plus.google.com/share?url=' + encodeURIComponent(url) + '" ';
		if (links == 'popup') {
			code += 'data-social-loader="popup"';
		} else {
			code += 'data-social-loader="blank"';
		}
		code += '>' +
			'<img ';
		if (language == "de") {
			code += 'title="Artikel teilen auf Google+"';
		} else if (language == "en") {
			code += 'title="share article on Google+"';
		} else if (language == "fr") {
			code += 'title="Partagez cet article sur Google+"';
		}
		code += 'src="/shared/vogelonline/img/bep30/smbutton/google.png">' +
			'</a>';
	}
	else if(layout == 'responsive')
	{
		var code = '<button class="gp" data-social-url="https://plus.google.com/share?url=' + encodeURIComponent(url) + '" ';
		if (links == 'popup') {
			code += 'data-social-loader="popup"';
		} else {
			code += 'data-social-loader="blank"';
		}
		code += '>' +
			'<img ';
		if (language == "de") {
			code += 'title="Artikel teilen auf Google+"';
		} else if (language == "en") {
			code += 'title="share article on Google+"';
		} else if (language == "fr") {
			code += 'title="Partagez cet article sur Google+"';
		}
		code += 'src="/shared/vogelonline/img/bep30/smbutton/google_128.png"><span>' + count + '</span><span class="sm-text">' + text + '</span></button>';
	}
	else
	{
		var code = '<div class="g-plusone" data-size="medium" data-href="'
			+ url
			+ '"></div><script type="text/javascript">window.___gcfg = {lang: "'
			+ language
			+ '"}; (function() { var po = document.createElement("script"); po.type = "text/javascript"; po.async = true; po.src = "https://apis.google.com/js/plusone.js"; var s = document.getElementsByTagName("script")[0]; s.parentNode.insertBefore(po, s); })(); </script>';
	}
	
	return code;

}

function getXing(layout,links,count,text,urlfix) {
	
	// Tracking: SiteCatalyst + Google Analytics
	var url = getUrlWithTrackingCode(urlfix,'sm-x-swyn','&utm_source=xing&utm_medium=sm&utm_campaign=xing-swyn');
	
	if(layout == 'custom')
	{
		var code = '<a class="xi" href="https://www.xing-share.com/app/user?op=share;sc_p=xing-share;url=' + encodeURIComponent(url) + '" ';
		if (links == 'popup') {
			code += 'data-social-loader="popup"';
		} else {
			code += 'data-social-loader="blank"';
		}
		code += '>' +
			'<img ';
		if (language == "de") {
			code += 'title="Artikel teilen auf Xing"';
		} else if (language == "en") {
			code += 'title="share article on Xing"';
		} else if (language == "fr") {
			code += 'title="Partagez cet article sur Xing"';
		}
		code += 'src="/shared/vogelonline/img/bep30/smbutton/xing.png">' +
			'</a>';
	}
	else if(layout == 'responsive')
	{
		var code = '<button class="xi" data-social-url="https://www.xing-share.com/app/user?op=share;sc_p=xing-share;url=' + encodeURIComponent(url) + '" ';
		if (links == 'popup') {
			code += 'data-social-loader="popup"';
		} else {
			code += 'data-social-loader="blank"';
		}
		code += '>' +
			'<img ';
		if (language == "de") {
			code += 'title="Artikel teilen auf Xing"';
		} else if (language == "en") {
			code += 'title="share article on Xing"';
		} else if (language == "fr") {
			code += 'title="Partagez cet article sur Xing"';
		}
		code += 'src="/shared/vogelonline/img/bep30/smbutton/xing_128.svg"><span>' + count + '</span><span class="sm-text">' + text + '</span></button>';
	}
	else
	{
		var code = '<script data-url="'
			+ url
			+ '" data-lang="de" data-counter="right" type="XING/Share"></script>'
			+ '<script>' + ';(function(d, s) {' + 'var x = d.createElement(s),'
			+ 's = d.getElementsByTagName(s)[0];'
			+ "x.src ='https://www.xing-share.com/js/external/share.js';"
			+ 's.parentNode.insertBefore(x, s);' + "})(document, 'script');"
			+ '</script>';
	}
	
	return code;

}

function getLinkedIn(layout,links,count,text,urlfix) {
	
	// Tracking: SiteCatalyst + Google Analytics
	var url = getUrlWithTrackingCode(urlfix,'sm-li-swyn','&utm_source=linkedin&utm_medium=sm&utm_campaign=linkedin-swyn');
	
	var title = getTitle();
	
	if(layout == 'custom')
	{
		var code = '<a class="li" href="http://www.linkedin.com/shareArticle?mini=true&url=' + encodeURIComponent(url) + '&title=' + title + '" ';
		if (links == 'popup') {
			code += 'data-social-loader="popup"';
		} else {
			code += 'data-social-loader="blank"';
		}
		code += '>' +
			'<img ';
		if (language == "de") {
			code += 'title="Artikel teilen auf LinkedIn"';
		} else if (language == "en") {
			code += 'title="share article on LinkedIn"';
		} else if (language == "fr") {
			code += 'title="Partagez cet article sur LinkedIn"';
		}
		code += 'src="/shared/vogelonline/img/bep30/smbutton/linkedin.png">' +
			'</a>';
	}
	else if(layout == 'responsive')
	{
		var code = '<button class="li" data-social-url="http://www.linkedin.com/shareArticle?mini=true&url=' + encodeURIComponent(url) + '&title=' + title + '" ';
		if (links == 'popup') {
			code += 'data-social-loader="popup"';
		} else {
			code += 'data-social-loader="blank"';
		}
		code += '>' +
			'<img ';
		if (language == "de") {
			code += 'title="Artikel teilen auf LinkedIn"';
		} else if (language == "en") {
			code += 'title="share article on LinkedIn"';
		} else if (language == "fr") {
			code += 'title="Partagez cet article sur LinkedIn"';
		}
		code += 'src="/shared/vogelonline/img/bep30/smbutton/linkedin_128.svg"><span>' + count + '</span><span class="sm-text">' + text + '</span></button>';
	}
	else
	{
		var code = '<script src="//platform.linkedin.com/in.js"'
			+ 'type="text/javascript"></script><script type="IN/Share" data-url="'
			+ url + '" data-counter="right" width="80px"></script>';
	}
	
	return code;
}
function getWhatsapp(layout,links,count,text,urlfix,areaElements) {
	var code = '';
	if(navigator.userAgent.match(/Android|iPhone/i) && !navigator.userAgent.match(/iPod|iPad/i))
	{
		// Tracking: SiteCatalyst + Google Analytics
		var url = getUrlWithTrackingCode(urlfix,'sm-li-swyn','&utm_source=whatsapp&utm_medium=sm&utm_campaign=whatsapp-swyn');
		
		var title = $('meta[property="og:title"]').attr("content");
		
		if(layout == 'custom')
		{
			code = '<a class="li" href="WhatsApp://send?text=' + encodeURIComponent(title) + '%0A%0A' + encodeURIComponent(url) + '">' +
				'<img ';
			if (language == "de") {
				code += 'title="Artikel teilen auf Whatsapp"';
			} else if (language == "en") {
				code += 'title="share article on Whatsapp"';
			} else if (language == "fr") {
				code += 'title="Partagez cet article sur Whatsapp"';
			}
			code += 'src="/shared/vogelonline/img/bep30/smbutton/whatsapp.png">' +
				'</a>';
		}
		else // Keine weitere Variante vorhanden
		{
			code = '<a class="li" href="WhatsApp://send?text=' + encodeURIComponent(title) + '%0A%0A' + encodeURIComponent(url) + '">' +
				'<img ';
			if (language == "de") {
				code += 'title="Artikel teilen auf Whatsapp"';
			} else if (language == "en") {
				code += 'title="share article on Whatsapp"';
			} else if (language == "fr") {
				code += 'title="Partagez cet article sur Whatsapp"';
			}
			code += 'src="/shared/vogelonline/img/bep30/smbutton/whatsapp_128.png"><span>' + count + '</span><span class="sm-text">' + text + '</span></a>';
		}
	}
	else
	{
		$(areaElements).find('#whatsapp').remove();
	}
	return code;
}