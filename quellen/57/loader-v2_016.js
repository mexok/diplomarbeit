(function() {

    var __hs_cta_json = {"css":"a#cta_button_149513_59d8b851-c24b-4b4a-8fe3-0d45b60e5651 {\n  cursor:pointer; \n}\na#cta_button_149513_59d8b851-c24b-4b4a-8fe3-0d45b60e5651:hover {\n}\na#cta_button_149513_59d8b851-c24b-4b4a-8fe3-0d45b60e5651:active, #cta_button_149513_59d8b851-c24b-4b4a-8fe3-0d45b60e5651:active:hover {\n}\n\n","image_html":"<a id=\"cta_button_149513_59d8b851-c24b-4b4a-8fe3-0d45b60e5651\" class=\"cta_button\" href=\"https://cta-service-cms2.hubspot.com/ctas/v2/public/cs/c/?cta_guid=59d8b851-c24b-4b4a-8fe3-0d45b60e5651&placement_guid=84d0a24d-1b3e-40f8-9884-9ac34d1a1ff0&portal_id=149513&canon=https%3A%2F%2Fwww.qt.io%2Fqt-features-libraries-apis-tools-and-ide%2F&redirect_url=APefjpFCC9-_x1f6xl5I4auIhqti1DffqoQ6sXxAiZGEB52iFZiQXSAbCb5V2oINtBLJrrrQ49yL0EUDUN-k0Pf5fCTO1m-xQim5URiP4m_fnoBbzv8PqTcdpiK_IAC5_hR3Oo9jRr34VIgx9guT6V5MQgJvDz1w4zBKHap2ljxcjybwsJBNJDttLEJBX6alj17dSeySVGyzNieO15w23syM-bs1WHI-tAdKUF-yT5ZrkI7A0sQXD0iN2ovhP5qHEs2Kq663HiK_u597CoBFOTUFjAmoHbJJ34Sm4ahSH0DzSS3LsKuHwlA&click=53d11d37-7c00-405a-932b-c2b9f02ed9ec&hsutk=20e73c2c01ae0c2d7d7755cb402af00a&pageId=5316083699\"  target=\"_blank\"  cta_dest_link=\"https://doc.qt.io/QtForDeviceCreation/qt-configuration-tool.html\"><img id=\"hs-cta-img-84d0a24d-1b3e-40f8-9884-9ac34d1a1ff0\" class=\"hs-cta-img c-btn--small\" style=\"border-width: 0px; /*hs-extra-styles*/\" mce_noresize=\"1\" alt=\"Technical details\" src=\"https://cdn2.hubspot.net/hubshot/17/09/07/7f0fa5e2-8b79-4f33-b71f-ab24dfcc519e.png\" /></a>","is_image":false,"placement_element_class":"hs-cta-84d0a24d-1b3e-40f8-9884-9ac34d1a1ff0","raw_html":"<a id=\"cta_button_149513_59d8b851-c24b-4b4a-8fe3-0d45b60e5651\" class=\"cta_button c-btn--small\" href=\"https://cta-service-cms2.hubspot.com/ctas/v2/public/cs/c/?cta_guid=59d8b851-c24b-4b4a-8fe3-0d45b60e5651&placement_guid=84d0a24d-1b3e-40f8-9884-9ac34d1a1ff0&portal_id=149513&canon=https%3A%2F%2Fwww.qt.io%2Fqt-features-libraries-apis-tools-and-ide%2F&redirect_url=APefjpFCC9-_x1f6xl5I4auIhqti1DffqoQ6sXxAiZGEB52iFZiQXSAbCb5V2oINtBLJrrrQ49yL0EUDUN-k0Pf5fCTO1m-xQim5URiP4m_fnoBbzv8PqTcdpiK_IAC5_hR3Oo9jRr34VIgx9guT6V5MQgJvDz1w4zBKHap2ljxcjybwsJBNJDttLEJBX6alj17dSeySVGyzNieO15w23syM-bs1WHI-tAdKUF-yT5ZrkI7A0sQXD0iN2ovhP5qHEs2Kq663HiK_u597CoBFOTUFjAmoHbJJ34Sm4ahSH0DzSS3LsKuHwlA&click=53d11d37-7c00-405a-932b-c2b9f02ed9ec&hsutk=20e73c2c01ae0c2d7d7755cb402af00a&pageId=5316083699\" target=\"_blank\" style=\"/*hs-extra-styles*/\" cta_dest_link=\"https://doc.qt.io/QtForDeviceCreation/qt-configuration-tool.html\" title=\"Technical details\">Technical details</a>"};
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
            window.hbspt && hbspt.cta && hbspt.cta.afterLoad && hbspt.cta.afterLoad('84d0a24d-1b3e-40f8-9884-9ac34d1a1ff0');
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
    window._hsq.push(['trackCtaView', '84d0a24d-1b3e-40f8-9884-9ac34d1a1ff0', '59d8b851-c24b-4b4a-8fe3-0d45b60e5651']);
}());
