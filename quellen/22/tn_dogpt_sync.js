/*-------------------------------------------------------------------------------------------------*/
//TechNetwork GlobalScript dogpt sync
//Revision 1.1,14.03.2013,eh,Function gup auf Custom Parameter showroom umgestellt
//Revision 1.2,24.05.2013,eh,Debug DFP ID's hinzugefügt in //GPT Debug
//Revision 1.3,29.07.2013,eh,GPT Debug,Object idgStorage.ads initialisiert
//Revision 1.3.1,10.12.2013,eh,Get Keywords Blank Replacement entfernt
//Revision 1.4,24.02.2015,eh, Define Slots an GPT global angepasst
//Revision 1.5,31.08.2015,eh,inner browser size added,sticky leaderboard added
//Revision 1.6,19.05.2016,eh,score2 custom targeting added
//Revision 1.7,04.08.2016,eh,Debug DFP Ids changed
/*-------------------------------------------------------------------------------------------------*/
//Get inner browser size, added 31.08.2015
idgStorage.ibw = (window.innerWidth);
idgStorage.ibh = (window.innerHeight);
//Get URL Parameter
function gup(name, defvalue) {
name = name.replace(/[\[]/,"\\\[").replace(/[\]]/,"\\\]");
var regexS = "[\\?&]"+name+"=([^&#]*)";
var regex = new RegExp( regexS );
var results = regex.exec( window.location.href );
if( results == null )
return defvalue;
else
return results[1].replace(/[^a-zA-Z\/\-\_]/g, '');
}
//Get Keywords
var rs_tax = [];
var metatags = jQuery('meta[name=keywords]').attr("content");
   if (metatags != '' && metatags != undefined) {
    strmetatags = metatags.toLowerCase().replace(/&amp;/g, "").replace(/&/g, "").replace(/ü/g, "ue").replace(/ä/g, "ae").replace(/ö/g, "oe").replace(/ß/g, "ss").split(",");
    for(var i=0,len=strmetatags.length; value=strmetatags[i], i<len; i++) {
    rs_tax.push(jQuery.trim(value));
    }
} else {
rs_tax.push(idgStorage.rs_tax);
}
//GPT Debug
function debugGoogleAds(){
var debugwindow = window.open('', 'DebugWindow', 'width=600,height=800,dependent=yes,scrollbars=yes');
var htmlcode = '<html><head><title>DART Debug</title></head><body><div id="debugcode">';
htmlcode += '<h2>Dartpath</h2><p>' + idgStorage.adUnit + '</p>';
htmlcode += '<h2>Sec</h2><p>' + idgStorage.sec + '</p>';
htmlcode += '<h2>Showroom</h2><p>' + idgStorage.showroom + '</p>';
htmlcode += '<h2>Tax</h2><p>' + rs_tax + '</p>';
htmlcode += '<h2>Inner Browser Width</h2><p>' + idgStorage.ibw + '</p>';//added 31.08.2015
htmlcode += '<h2>Inner Browser Height</h2><p>' + idgStorage.ibh + '</p>';//added 31.08.2015
htmlcode += '<h2>Positions</h2>';
jQuery(".idgGoogleAdTag").each(function() {
var id = jQuery(this).attr("id");
var name = id.replace(/^ad_/, "");
if (typeof dfpIds[name] != 'undefined'){
var idgDebug = new Object();
idgDebug.order_id = dfpIds[name].ebuy;
idgDebug.lineitem_id = dfpIds[name].eaid;
idgDebug.creative_id = dfpIds[name].ecid;
} else {
var idgDebug = new Object();
idgDebug.order_id = 'no_id';
idgDebug.lineitem_id = 'no_id';
idgDebug.creative_id = 'no_id';
}
var sizeval = jQuery(this).attr("data-idg-sizes");
var sizes = [];
if (typeof sizeval != 'undefined') {
sizes = JSON.parse(sizeval);
}
if (typeof sizes[0] != 'undefined') {
htmlcode += '<h3>Pos = ' + name + '</h3><p>sizes = ' + JSON.stringify(sizes) + ' <br/>width/height of ' +id+ ' = ' + jQuery(this).width() + ' x ' + jQuery(this).height() + (jQuery(this).css('display')=='none'?' collapsed':' shown')+ '<br/>';
htmlcode += 'Order ID: ' + idgDebug.order_id + '<br/>';
htmlcode += 'Line Item ID: ' + idgDebug.lineitem_id + '<br/>';
htmlcode += 'Creative ID: ' + idgDebug.creative_id + '</p>';
} else {
htmlcode += '<h3>(OutofPage) Pos = ' + name + '</h3><p>sizes = ' + JSON.stringify(sizes) + ' <br/>width/height of ' +id+ ' = ' + jQuery(this).width() + ' x ' + jQuery(this).height() + (jQuery(this).css('display')=='none'?' collapsed':' shown')+ '<br/>';
htmlcode += 'Order ID: ' + idgDebug.order_id + '<br/>';
htmlcode += 'Line Item ID: ' + idgDebug.lineitem_id + '<br/>';
htmlcode += 'Creative ID: ' + idgDebug.creative_id + '</p>';
}
});
htmlcode += '</div></body>';
debugwindow.document.open();
debugwindow.document.write(htmlcode);
debugwindow.document.close();
}
// Define Slots
if (idgStorage.adUnit2 != '' && idgStorage.adUnit2 != undefined) {
idgStorage.adUnit = idgStorage.adUnit1 +'/'+ idgStorage.adUnit2;
} else {
idgStorage.adUnit = idgStorage.adUnit1;
}
idgStorage.showroom = gup("use_dart_path", "undefined");
// More infos
if (idgStorage.score2 != '' && idgStorage.score2 != undefined) {
idgStorage.score = idgStorage.score2;
} else {
idgStorage.score = "undefined";
}
googletag.pubads().setTargeting('ibw', [idgStorage.ibw]);
googletag.pubads().setTargeting('ibh', [idgStorage.ibh]);
googletag.pubads().setTargeting('type', 'sync');
googletag.pubads().setTargeting('tax', rs_tax);
googletag.pubads().setTargeting('sec', idgStorage.sec);
googletag.pubads().setTargeting('showroom', idgStorage.showroom);
googletag.pubads().setTargeting('score2', idgStorage.score);
googletag.pubads().enableSyncRendering();
googletag.pubads().collapseEmptyDivs();
//Sticky Leaderboard
(function (a) {
    a.stickyLeaderboard = {
        init: function (b) {
            var d = a(this);
            if (d.height() == 0) {
                setTimeout(function () {
                    d.stickyLeaderboard(b)
                }, 300);
                return
            }
            var e = a('<div></div>');
            e.css('height', d.height());
            e.css('width', d.width());
            d.css('height', d.height());
            d.css('width', d.width());
            var c = setInterval(function () {
                e.css('height', d.height())
            }, 250);
            a.stickyLeaderboard.stick(e, d);
            if (typeof b != 'undefined' && 'timeout' in b && b.timeout > 0) {
                setTimeout(function () {
                    clearInterval(c);
                    a.stickyLeaderboard.unstick(e, d)
                }, b.timeout)
            }
            return d
        },
        stick: function (c, b) {
            b.after(c);
            b.css('position', 'fixed');
            b.css('z-index', '2500')
        },
        unstick: function (c, b) {
            c.hide();
            b.css('position', 'static')
        }
    };
    a.fn.stickyLeaderboard = function (b) {
        if (a.stickyLeaderboard[b]) {
            return a.stickyLeaderboard[b].apply(this, Array.prototype.slice.call(arguments, 1))
        } else {
            if (typeof b === 'object' || !b) {
                return a.stickyLeaderboard.init.apply(this, arguments)
            } else {
            }
        }
    }
}) (jQuery);