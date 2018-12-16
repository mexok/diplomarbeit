(function() {

    var __hs_cta_json = {"css":"a#cta_button_149513_dc113a62-982d-4340-8e12-d8b77c737c1f {\n  cursor:pointer; \n}\na#cta_button_149513_dc113a62-982d-4340-8e12-d8b77c737c1f:hover {\n}\na#cta_button_149513_dc113a62-982d-4340-8e12-d8b77c737c1f:active, #cta_button_149513_dc113a62-982d-4340-8e12-d8b77c737c1f:active:hover {\n}\n\n","image_html":"<a id=\"cta_button_149513_dc113a62-982d-4340-8e12-d8b77c737c1f\" class=\"cta_button\" href=\"https://cta-service-cms2.hubspot.com/ctas/v2/public/cs/c/?cta_guid=dc113a62-982d-4340-8e12-d8b77c737c1f&placement_guid=73b5220d-dd2a-430a-892f-44558ec93f2b&portal_id=149513&canon=https%3A%2F%2Fwww.qt.io%2Fwhat-is-qt%2F&redirect_url=APefjpEjVejcClpi9eO0HuhXfmTwYtvUg02Vop8nX_Kvf9etKhX9Q2goPcARGzO_YL1yEvOwRysKyKl0GtelY8K46zNLbSapK1P532NcHPx4ffslcoSHbrcmZBT5QtlEYMo3tzqHMsOG52Hd0-oas3v3kaVZuq2J8-2ObFuhGK3m5Jpz_aeKL800n8nf09Ix_6DcFp4mO1TvdBJ3OZLnbXUddEFZ0XnrygraC-GeDG8UksxX94TEZ-c&click=c5338146-b5e3-4b9c-b199-452027ece188&hsutk=20e73c2c01ae0c2d7d7755cb402af00a&pageId=5294071221\"  cta_dest_link=\"https://www.qt.io/built-with-qt/\"><img id=\"hs-cta-img-73b5220d-dd2a-430a-892f-44558ec93f2b\" class=\"hs-cta-img c-btn--small\" style=\"border-width: 0px; /*hs-extra-styles*/\" mce_noresize=\"1\" alt=\"Customer cases\" src=\"https://cdn2.hubspot.net/hubshot/17/09/06/5574b921-b828-46f7-83c8-178cf8f5cc64.png\" /></a>","is_image":false,"placement_element_class":"hs-cta-73b5220d-dd2a-430a-892f-44558ec93f2b","raw_html":"<a id=\"cta_button_149513_dc113a62-982d-4340-8e12-d8b77c737c1f\" class=\"cta_button c-btn--small\" href=\"https://cta-service-cms2.hubspot.com/ctas/v2/public/cs/c/?cta_guid=dc113a62-982d-4340-8e12-d8b77c737c1f&placement_guid=73b5220d-dd2a-430a-892f-44558ec93f2b&portal_id=149513&canon=https%3A%2F%2Fwww.qt.io%2Fwhat-is-qt%2F&redirect_url=APefjpEjVejcClpi9eO0HuhXfmTwYtvUg02Vop8nX_Kvf9etKhX9Q2goPcARGzO_YL1yEvOwRysKyKl0GtelY8K46zNLbSapK1P532NcHPx4ffslcoSHbrcmZBT5QtlEYMo3tzqHMsOG52Hd0-oas3v3kaVZuq2J8-2ObFuhGK3m5Jpz_aeKL800n8nf09Ix_6DcFp4mO1TvdBJ3OZLnbXUddEFZ0XnrygraC-GeDG8UksxX94TEZ-c&click=c5338146-b5e3-4b9c-b199-452027ece188&hsutk=20e73c2c01ae0c2d7d7755cb402af00a&pageId=5294071221\"  style=\"/*hs-extra-styles*/\" cta_dest_link=\"https://www.qt.io/built-with-qt/\" title=\"Customer cases\">Customer cases</a>"};
    var __hs_cta = {};

    __hs_cta.drop = function() {
        var is_legacy = document.getElementById('hs-cta-ie-element') && true || false,
            html = __hs_cta_json.image_html,
            tags = __hs_cta.getTags(),
            is_image = __hs_cta_json.is_image,
            parent, _style;

        if (!is_legacy && !is_image) {
            parent = (document.getElementsByTagName("head")[0]||document.getElementsByTagName("body")[0]);

            _style = document.createElement('style');
            parent.insertBefore(_style, parent.childNodes[0]);
            try {
                default_css = ".hs-cta-wrapper p, .hs-cta-wrapper div { margin: 0; padding: 0; }";
                cta_css = default_css + " " + __hs_cta_json.css;
                // http://blog.coderlab.us/2005/09/22/using-the-innertext-property-with-firefox/
                _style[document.all ? 'innerText' : 'textContent'] = cta_css;
            } catch (e) {
                // addressing an ie9 issue
                _style.styleSheet.cssText = cta_css;
            }

            html = __hs_cta_json.raw_html;
        }

        for (var i = 0; i < tags.length; ++i) {

            var tag = tags[i];
            var images = tag.getElementsByTagName('img');
            var cssText = "";
            var align = "";
            for (var j = 0; j < images.length; j++) {
                align = images[j].align;
                images[j].style.border = '';
                images[j].style.display = '';
                cssText = images[j].style.cssText;
            }

            if (align == "right") {
                tag.style.display = "block";
                tag.style.textAlign = "right";
            } else if (align == "middle") {
                tag.style.display = "block";
                tag.style.textAlign = "center";
            }

            tag.innerHTML = html.replace('/*hs-extra-styles*/', cssText);
            tag.style.visibility = 'visible';
            tag.setAttribute('data-hs-drop', 'true');
            window.hbspt && hbspt.cta && hbspt.cta.afterLoad && hbspt.cta.afterLoad('73b5220d-dd2a-430a-892f-44558ec93f2b');
        }

        return tags;
    };

    __hs_cta.getTags = function() {
        var allTags, check, i, divTags, spanTags,
            tags = [];
            if (document.getElementsByClassName) {
                allTags = document.getElementsByClassName(__hs_cta_json.placement_element_class);
                check = function(ele) {
                    return (ele.nodeName == 'DIV' || ele.nodeName == 'SPAN') && (!ele.getAttribute('data-hs-drop'));
                };
            } else {
                allTags = [];
                divTags = document.getElementsByTagName("div");
                spanTags = document.getElementsByTagName("span");
                for (i = 0; i < spanTags.length; i++) {
                    allTags.push(spanTags[i]);
                }
                for (i = 0; i < divTags.length; i++) {
                    allTags.push(divTags[i]);
                }

                check = function(ele) {
                    return (ele.className.indexOf(__hs_cta_json.placement_element_class) > -1) && (!ele.getAttribute('data-hs-drop'));
                };
            }
            for (i = 0; i < allTags.length; ++i) {
                if (check(allTags[i])) {
                    tags.push(allTags[i]);
                }
            }
        return tags;
    };

    // need to do a slight timeout so IE has time to react
    setTimeout(__hs_cta.drop, 10);
    window._hsq = window._hsq || [];
    window._hsq.push(['trackCtaView', '73b5220d-dd2a-430a-892f-44558ec93f2b', 'dc113a62-982d-4340-8e12-d8b77c737c1f']);
}());
