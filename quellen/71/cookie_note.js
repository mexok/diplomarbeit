var cookie_note = {
	text: "Cookies erleichtern die Bereitstellung unserer Dienste. Mit der Nutzung unserer\
		  Dienste erklären Sie sich damit einverstanden, dass wir Cookies verwenden.",
	ok: "OK",
	revoke:"Widerrufen",
	forward: "Weitere Informationen",
	link: "http://www.google.com/intl/de/policies/technologies/cookies/",
	setJSCookie: function (cname, cvalue, exdays) {
	    var d = new Date();
	    d.setTime(d.getTime() + (exdays*24*60*60*1000));
	    var expires = "expires="+d.toUTCString();
	    document.cookie = cname + "=" + cvalue + ";path=/; " + expires;
	},	
    getJSCookie: function (cname) {
	    var name = cname + "=";
	    var ca = document.cookie.split(';');
	    for(var i=0; i<ca.length; i++) {
	        var c = ca[i];
	        while (c.charAt(0)==' ') c = c.substring(1);
	        if (c.indexOf(name) == 0) return c.substring(name.length, c.length);
	    }
	    return "";
	},
	deleteJSCookies: function () {
		document.cookie.split(";").forEach(function(c) { document.cookie = c.replace(/^ +/, "").replace(/=.*/, "=;expires=" + new Date().toUTCString() + ";path=/"); });
	},	
	deleteJSCookiesFromAllPaths: function () {
		var cookies = document.cookie.split("; ");
	    for (var c = 0; c < cookies.length; c++) {
	        var d = window.location.hostname.split(".");
	        while (d.length > 0) {
	            var cookieBase = encodeURIComponent(cookies[c].split(";")[0].split("=")[0]) + '=; expires=Thu, 01-Jan-1970 00:00:01 GMT; domain=' + d.join('.') + ' ;path=';
	            var p = location.pathname.split('/');
	            document.cookie = cookieBase + '/';
	            while (p.length > 0) {
	                document.cookie = cookieBase + p.join('/');
	                p.pop();
	            };
	            d.shift();
	        }
	    }
	},	
	removeCookies: function ()  {

		var res = document.cookie;
	    var multiple = res.split(";");
	    for(var i = 0; i < multiple.length; i++) {
	    	var key = multiple[i].split("=");
		if (key[0].trim() == "_ga"){
			window['ga-disable-'+ key[1]] = true;
		}
		if (key[0].trim() != 'revokecookies'){    
			document.cookie = key[0]+" =; expires = Thu, 01 Jan 1970 00:00:00 UTC";
		}
	    }

	},
	eraseCookieFromAllPaths: function(name) {
	    // This function will attempt to remove a cookie from all paths.
	    var pathBits = location.pathname.split('/');
	    var pathCurrent = ' path=';

	    // do a simple pathless delete first.
	    document.cookie = name + '=; expires=Thu, 01-Jan-1970 00:00:01 GMT;';

	    for (var i = 0; i < pathBits.length; i++) {
	        pathCurrent += ((pathCurrent.substr(-1) != '/') ? '/' : '') + pathBits[i];
	        document.cookie = name + '=; expires=Thu, 01-Jan-1970 00:00:01 GMT;' + pathCurrent + ';';
	    }
	},
	showNote: function(){
		
		function create(htmlStr) {
		    var frag = document.createDocumentFragment(),
		        temp = document.createElement('div');
		    temp.innerHTML = htmlStr;
		    while (temp.firstChild) {
		        frag.appendChild(temp.firstChild);
		    }
		    return frag;
		}
		if(this.getJSCookie('revokecookies') == "" )
		{
			var STR_htmlcode = '<div id="cookie-statement" style="line-height:1.8em;text-align: center;font-size: 0.7em;padding: 8px 1%;background-color:#9a9a9a;;color:#fff;width:98%;z-index: 12999;">\
				<div style="display: block;padding: 0 15px;">\
				  <span style="color:#fff">' + this.text + '</span>\
				  <a target="_blank" href="' + this.link + '" style="display: inline;margin-left: 0.5em;color: #FFF;cursor: pointer;white-space: nowrap;background-color: #6A6A6A;;padding: 3px 5px;text-decoration: none;border: 1px solid rgb(255, 255, 255);border-radius: 6px;">'+ this.forward +'</a>\
				  <a href="javascript:cookie_note.revokecookies()" id="revoke-cc-bar" style="display: inline;margin-left: 0.5em;color: #FFF;cursor: pointer;white-space: nowrap;padding: 3px 15px;text-decoration: none; border: 1px solid rgb(255, 255, 255);border-radius: 6px;">'+ this.revoke +'</a>\
				  <a href="javascript:cookie_note.hideOnOk()" id="close-cc-bar" style="display: inline;margin-left: 0.5em;color: #FFF;cursor: pointer;white-space: nowrap;background-color: #88bb88;padding: 3px 15px;text-decoration: none; border: 1px solid rgb(255, 255, 255);border-radius: 6px;">'+ this.ok +'</a>\
				  </div>\</div><style type="text/css" id="cookie-statement-style">#mobile-header {position: relative !important;} #adright.advertising {top: 37px !important;} #whitespace_click {top:40px !important} .sky {position:relative !important} .sky_hs1 {position:relative !important} .sky_hs2 {position:relative !important}</style>';
			
			var elem = document.getElementById("mobile-navi");

			if(elem != null &&  elem.offsetHeight > 0)
			{
				
				STR_htmlcode = '<div id="cookie-statement" style="line-height:1.8em;text-align: center;font-size: 0.7em;padding: 8px 1%;background-color:#9a9a9a;;color:#fff;width:98%;z-index: 12999;">\
					<div style="display: block;padding: 0 15px;">\
					  <span style="color:#fff">' + this.text + '</span>\
					  <a target="_blank" href="' + this.link + '" style="display: inline;margin-left: 0.5em;color: #FFF;cursor: pointer;white-space: nowrap;background-color: #6A6A6A;;padding: 3px 5px;text-decoration: none;border: 1px solid rgb(255, 255, 255);border-radius: 6px;">'+ this.forward +'</a>\
					  <a href="javascript:cookie_note.revokecookies()" id="revoke-cc-bar" style="display: inline;margin-left: 0.5em;color: #FFF;cursor: pointer;white-space: nowrap;padding: 3px 15px;text-decoration: none; border: 1px solid rgb(255, 255, 255);border-radius: 6px;">'+ this.revoke +'</a>\
					  <a href="javascript:cookie_note.hideOnOk()" id="close-cc-bar" style="display: inline;margin-left: 0.5em;color: #FFF;cursor: pointer;white-space: nowrap;background-color: #88bb88;padding: 3px 15px;text-decoration: none; border: 1px solid rgb(255, 255, 255);border-radius: 6px;">'+ this.ok +'</a>\
					  </div>\</div><style type="text/css" id="cookie-statement-style">#mobile-header {position: relative !important;} #whitespace_click {top:40px !important} .sky {position:relative !important} .sky_hs1 {position:relative !important} .sky_hs2 {position:relative !important} @media only screen and (max-width: 1024px) { #wrapper{margin-top: 0 !important;}}</style>';			
			}
		}
		else{
			var STR_htmlcode = '<div id="cookie-statement" style="line-height:1.8em;text-align: center;font-size: 0.7em;padding: 8px 1%;background-color:#9a9a9a;;color:#fff;width:98%;z-index: 12999;">\
				<div style="display: block;padding: 0 15px;">\
				  <span style="color:#fff">' + this.text + '</span>\
				  <a target="_blank" href="' + this.link + '" style="display: inline;margin-left: 0.5em;color: #FFF;cursor: pointer;white-space: nowrap;background-color: #6A6A6A;;padding: 3px 5px;text-decoration: none;border: 1px solid rgb(255, 255, 255);border-radius: 6px;">'+ this.forward +'</a>\<a href="javascript:cookie_note.hideOnOk()" id="close-cc-bar" style="display: inline;margin-left: 0.5em;color: #FFF;cursor: pointer;white-space: nowrap;background-color: #88bb88;padding: 3px 15px;text-decoration: none; border: 1px solid rgb(255, 255, 255);border-radius: 6px;">'+ this.ok +'</a>\
				  </div>\</div><style type="text/css" id="cookie-statement-style">#mobile-header {position: relative !important;} #adright.advertising {top: 37px !important;} #whitespace_click {top:40px !important} .sky {position:relative !important} .sky_hs1 {position:relative !important} .sky_hs2 {position:relative !important}</style>';
			
			var elem = document.getElementById("mobile-navi");

			if(elem != null &&  elem.offsetHeight > 0)
			{
				
				STR_htmlcode = '<div id="cookie-statement" style="line-height:1.8em;text-align: center;font-size: 0.7em;padding: 8px 1%;background-color:#9a9a9a;;color:#fff;width:98%;z-index: 12999;">\
					<div style="display: block;padding: 0 15px;">\
					  <span style="color:#fff">' + this.text + '</span>\
					  <a target="_blank" href="' + this.link + '" style="display: inline;margin-left: 0.5em;color: #FFF;cursor: pointer;white-space: nowrap;background-color: #6A6A6A;;padding: 3px 5px;text-decoration: none;border: 1px solid rgb(255, 255, 255);border-radius: 6px;">'+ this.forward +'</a>\<a href="javascript:cookie_note.hideOnOk()" id="close-cc-bar" style="display: inline;margin-left: 0.5em;color: #FFF;cursor: pointer;white-space: nowrap;background-color: #88bb88;padding: 3px 15px;text-decoration: none; border: 1px solid rgb(255, 255, 255);border-radius: 6px;">'+ this.ok +'</a>\
					  </div>\</div><style type="text/css" id="cookie-statement-style">#mobile-header {position: relative !important;} #whitespace_click {top:40px !important} .sky {position:relative !important} .sky_hs1 {position:relative !important} .sky_hs2 {position:relative !important} @media only screen and (max-width: 1024px) { #wrapper{margin-top: 0 !important;}}</style>';			
			}
		}
		var fragment = create(STR_htmlcode);
		
		
		// You can use native DOM methods to insert the fragment:
		document.body.insertBefore(fragment, document.body.childNodes[0]);
		
		
		document.write();
	},
	getPolicyLink: function(value)
	{
	    var allInputs = document.getElementsByTagName("a");
	    for(var x=0;x<allInputs.length;x++)
	        if(allInputs[x].innerHTML == value)
	            this.link = allInputs[x].getAttribute ("href");
	},
	//cookies loeschen
	revokecookies: function(){

	//	this.removeCookies();
	//	this.deleteJSCookiesFromAllPaths();
		this.setJSCookie("revokecookies",false,3365);
		window.location =  "/?pid=15911";
	},
	hideOnOk: function(){
		document.cookie = "revokecookies=; expires = Thu, 01 Jan 1970 00:00:00 UTC";
		if (	this.getJSCookie('revokecookies') != "")
		{	
			this.deleteJSCookies();	
			this.setJSCookie("cnoteshown",true,3365);
			this.setJSCookie("acceptcnote",true,3365);
			document.getElementById("cookie-statement").style.display = 'none';
			var elem = document.getElementById("cookie-statement-style");
			elem.parentNode.removeChild(elem);
			// damit alles getrackt wird wo sich gerade der kunde befindet
			location.reload();
			
		}
		else{
			this.setJSCookie("cnoteshown",true,3365);
			this.setJSCookie("acceptcnote",true,3365);
			document.getElementById("cookie-statement").style.display = 'none';
			var elem = document.getElementById("cookie-statement-style");
			elem.parentNode.removeChild(elem);
		}
	},	
	check: function(){
		//Falls Dominik und Flo doch nicht Recht haben und man eine neue Erteilung braucht;nur das wieder rein; alles andere greift drauf ab
	/*	if(this.getJSCookie('acceptcnote') != true)
		{
			this.removeCookies();
			this.deleteJSCookiesFromAllPaths();
		}*/
			
		if(this.getJSCookie('revokecookies') == "true" && this.getJSCookie('acceptcnote') == ""  )
		{
			this.removeCookies();
			//this.deleteJSCookiesFromAllPaths();
			//this.setJSCookie("revokecookies",true,3365);
		}
		else if(this.getJSCookie('revokecookies') != "" && this.getJSCookie('acceptcnote') != ""  )
		{
			document.cookie = "revokecookies=; expires = Thu, 01 Jan 1970 00:00:00 UTC";
		}
		if(this.getJSCookie('cnoteshown') == "")
		{
			if(arr_cookie['lang'] == "en")
			{
				this.text = "Our website stores cookies in your browser. These cookies are used to improve our website and provide more personalized services to you.";
				this.ok = "ok";
				this.revoke = "revoke";
				cookie_note.forward = "read more";
				this.getPolicyLink("Privacy Notice");
			}
			else
			{
				this.getPolicyLink("Datenschutz");
			}
			
			this.showNote();
		}

	},		
}
cookie_note.check();
/*
var xmlhttp;
if (window.XMLHttpRequest)
  {// code for IE7+, Firefox, Chrome, Opera, Safari
  xmlhttp=new XMLHttpRequest();
  }
else
  {// code for IE6, IE5
  xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
  }

xmlhttp.open("GET",arr_cookie['prot']+ document.location.host + "/shared/cookie_note/cookieExists",true);
xmlhttp.send();

alert(xmlhttp.responseText);
*/