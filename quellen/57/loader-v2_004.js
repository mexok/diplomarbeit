(function() {

    var __hs_cta_json = {"css":"a#cta_button_149513_76e88c4e-e650-4dc8-8023-549c864472d5 {\n  cursor:pointer; \n}\na#cta_button_149513_76e88c4e-e650-4dc8-8023-549c864472d5:hover {\n}\na#cta_button_149513_76e88c4e-e650-4dc8-8023-549c864472d5:active, #cta_button_149513_76e88c4e-e650-4dc8-8023-549c864472d5:active:hover {\n}\n\n","image_html":"<a id=\"cta_button_149513_76e88c4e-e650-4dc8-8023-549c864472d5\" class=\"cta_button\" href=\"https://cta-service-cms2.hubspot.com/ctas/v2/public/cs/c/?cta_guid=76e88c4e-e650-4dc8-8023-549c864472d5&placement_guid=80532ec4-0667-4a49-8759-db1f6d35960c&portal_id=149513&canon=https%3A%2F%2Fwww.qt.io%2Fqt-features-libraries-apis-tools-and-ide%2F&redirect_url=APefjpEZVH43eyN5wrPgwCpZjqu5qYly1AvFF3ex1mZoahYcX5jboUVEb_s0B0m9h0ReaGp4Ckhi_1nJWIPk6lm3xWuYsilQUgO856Er1KKZjjvhClo2k77l6u03bdh8lSpbAL4z7_D9vaFd8xvi6fS54B0A-NICiBIcvaEvdqjlrpCFR1641XBks8yDWefeOLQ157idNaBQZgXH5zipHyZ1cBMIH9HhwdzRtJoxMbs_FBrnr9hFGZBOP0N8KQylHYuiCG3ZRZyDa3W-KwEOLUOoiFtE6gpBJRe92mKc3dkL2KXUh5lSXHI&click=41a55cd8-7cec-4333-a147-425bd2ae5f18&hsutk=20e73c2c01ae0c2d7d7755cb402af00a&pageId=5316083699\"  target=\"_blank\"  cta_dest_link=\"https://doc.qt.io/qtcreator/creator-build-settings.html\"><img id=\"hs-cta-img-80532ec4-0667-4a49-8759-db1f6d35960c\" class=\"hs-cta-img c-btn--small\" style=\"border-width: 0px; /*hs-extra-styles*/\" mce_noresize=\"1\" alt=\"Technical details\" src=\"https://cdn2.hubspot.net/hubshot/17/09/07/809e92a9-81af-431b-8fb3-c025d7ec6b64.png\" /></a>","is_image":false,"placement_element_class":"hs-cta-80532ec4-0667-4a49-8759-db1f6d35960c","raw_html":"<a id=\"cta_button_149513_76e88c4e-e650-4dc8-8023-549c864472d5\" class=\"cta_button c-btn--small\" href=\"https://cta-service-cms2.hubspot.com/ctas/v2/public/cs/c/?cta_guid=76e88c4e-e650-4dc8-8023-549c864472d5&placement_guid=80532ec4-0667-4a49-8759-db1f6d35960c&portal_id=149513&canon=https%3A%2F%2Fwww.qt.io%2Fqt-features-libraries-apis-tools-and-ide%2F&redirect_url=APefjpEZVH43eyN5wrPgwCpZjqu5qYly1AvFF3ex1mZoahYcX5jboUVEb_s0B0m9h0ReaGp4Ckhi_1nJWIPk6lm3xWuYsilQUgO856Er1KKZjjvhClo2k77l6u03bdh8lSpbAL4z7_D9vaFd8xvi6fS54B0A-NICiBIcvaEvdqjlrpCFR1641XBks8yDWefeOLQ157idNaBQZgXH5zipHyZ1cBMIH9HhwdzRtJoxMbs_FBrnr9hFGZBOP0N8KQylHYuiCG3ZRZyDa3W-KwEOLUOoiFtE6gpBJRe92mKc3dkL2KXUh5lSXHI&click=41a55cd8-7cec-4333-a147-425bd2ae5f18&hsutk=20e73c2c01ae0c2d7d7755cb402af00a&pageId=5316083699\" target=\"_blank\" style=\"/*hs-extra-styles*/\" cta_dest_link=\"https://doc.qt.io/qtcreator/creator-build-settings.html\" title=\"Technical details\">Technical details</a>"};
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
            window.hbspt && hbspt.cta && hbspt.cta.afterLoad && hbspt.cta.afterLoad('80532ec4-0667-4a49-8759-db1f6d35960c');
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
    window._hsq.push(['trackCtaView', '80532ec4-0667-4a49-8759-db1f6d35960c', '76e88c4e-e650-4dc8-8023-549c864472d5']);
}());
