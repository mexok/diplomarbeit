(function() {

    var __hs_cta_json = {"css":"a#cta_button_149513_22dabe7c-695a-44e5-9903-ee7424e2d0bb {\n  cursor:pointer; \n}\na#cta_button_149513_22dabe7c-695a-44e5-9903-ee7424e2d0bb:hover {\n}\na#cta_button_149513_22dabe7c-695a-44e5-9903-ee7424e2d0bb:active, #cta_button_149513_22dabe7c-695a-44e5-9903-ee7424e2d0bb:active:hover {\n}\n\n","image_html":"<a id=\"cta_button_149513_22dabe7c-695a-44e5-9903-ee7424e2d0bb\" class=\"cta_button\" href=\"https://cta-service-cms2.hubspot.com/ctas/v2/public/cs/c/?cta_guid=22dabe7c-695a-44e5-9903-ee7424e2d0bb&placement_guid=cb8bcdd6-13a1-4e5c-97ed-0f1b9c2949f4&portal_id=149513&canon=https%3A%2F%2Fwww.qt.io%2Fwhat-is-qt%2F&redirect_url=APefjpHjhoUEZoc14w3VYvX1nKU3b43tuFrTL54pvqIeySYiafTVIlTWag1IVOjQHugxkqVlBGrKs_rkpKAb2O05AD1QQl8JcjQ9V5Z95DyOt8nw7S-TarafAzf6gOFTCnOC5AHXlxsHWnBHA1Z21EELmlG6516ACjhwC8FcDJU6oL_rk9J-X-ArIL2y4G7dZq3keQEPTCdM8j9VXmcCCKDnisz75jf57b2xaMN6EfbRJ6uOwc_cMEPTAseRGEdpaDVZQAe04Ns6&click=ac46296f-0475-4ed2-8d8f-93f39d94a734&hsutk=20e73c2c01ae0c2d7d7755cb402af00a&pageId=5294071221\"  cta_dest_link=\"https://www.qt.io/lg-electronics-built-with-qt\"><img id=\"hs-cta-img-cb8bcdd6-13a1-4e5c-97ed-0f1b9c2949f4\" class=\"hs-cta-img c-btn--small\" style=\"border-width: 0px; /*hs-extra-styles*/\" mce_noresize=\"1\" alt=\"LG&#39;s story\" src=\"https://cdn2.hubspot.net/hubshot/18/03/02/aa0812f1-c377-4c17-b0d8-2e26a6821672.png\" /></a>","is_image":false,"placement_element_class":"hs-cta-cb8bcdd6-13a1-4e5c-97ed-0f1b9c2949f4","raw_html":"<a id=\"cta_button_149513_22dabe7c-695a-44e5-9903-ee7424e2d0bb\" class=\"cta_button c-btn--small\" href=\"https://cta-service-cms2.hubspot.com/ctas/v2/public/cs/c/?cta_guid=22dabe7c-695a-44e5-9903-ee7424e2d0bb&placement_guid=cb8bcdd6-13a1-4e5c-97ed-0f1b9c2949f4&portal_id=149513&canon=https%3A%2F%2Fwww.qt.io%2Fwhat-is-qt%2F&redirect_url=APefjpHjhoUEZoc14w3VYvX1nKU3b43tuFrTL54pvqIeySYiafTVIlTWag1IVOjQHugxkqVlBGrKs_rkpKAb2O05AD1QQl8JcjQ9V5Z95DyOt8nw7S-TarafAzf6gOFTCnOC5AHXlxsHWnBHA1Z21EELmlG6516ACjhwC8FcDJU6oL_rk9J-X-ArIL2y4G7dZq3keQEPTCdM8j9VXmcCCKDnisz75jf57b2xaMN6EfbRJ6uOwc_cMEPTAseRGEdpaDVZQAe04Ns6&click=ac46296f-0475-4ed2-8d8f-93f39d94a734&hsutk=20e73c2c01ae0c2d7d7755cb402af00a&pageId=5294071221\"  style=\"/*hs-extra-styles*/\" cta_dest_link=\"https://www.qt.io/lg-electronics-built-with-qt\" title=\"LG&#39;s story\">LG's story</a>"};
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
            window.hbspt && hbspt.cta && hbspt.cta.afterLoad && hbspt.cta.afterLoad('cb8bcdd6-13a1-4e5c-97ed-0f1b9c2949f4');
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
    window._hsq.push(['trackCtaView', 'cb8bcdd6-13a1-4e5c-97ed-0f1b9c2949f4', '22dabe7c-695a-44e5-9903-ee7424e2d0bb']);
}());
