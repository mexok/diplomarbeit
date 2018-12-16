(function() {

    var __hs_cta_json = {"css":"a#cta_button_149513_643bd8f4-2c59-4c4c-ba1a-4aaa05b51086 {\n  cursor:pointer; \n}\na#cta_button_149513_643bd8f4-2c59-4c4c-ba1a-4aaa05b51086:hover {\n}\na#cta_button_149513_643bd8f4-2c59-4c4c-ba1a-4aaa05b51086:active, #cta_button_149513_643bd8f4-2c59-4c4c-ba1a-4aaa05b51086:active:hover {\n}\n\n","image_html":"<a id=\"cta_button_149513_643bd8f4-2c59-4c4c-ba1a-4aaa05b51086\" class=\"cta_button\" href=\"https://cta-service-cms2.hubspot.com/ctas/v2/public/cs/c/?cta_guid=643bd8f4-2c59-4c4c-ba1a-4aaa05b51086&placement_guid=c80600ba-f2ea-45ed-97ef-6949c1c4c236&portal_id=149513&canon=https%3A%2F%2Fwww.qt.io%2Fqt-features-libraries-apis-tools-and-ide%2F&redirect_url=APefjpGmlR1pYkJ4Ccy1tc-702nNO0nhmJwk7gBnziCVXmDGfoNh_qB0gvlXqFpUTOOWf57yAEVrImi9ZSoLbt2QZluy1tj-OKpLHxlW-6zA6CZwoH79oVDjmjDqqUBVXcXUH0k_lpaTrt3YddEsgApnhvXfKuQcv0Co3YE-XhjiFbEqDJp_Ln7B316TZWYAP7w3GSnrxsOYJdXO0WXChj_Hfb7thZrNM8Rep-YdQ166Qg0hvAc1_JScAucstvYf6QfOv5bUoDFa7cmDCJRTfqavczB2JR1igUf4FBTEhbPeklbBxADJJ9Y&click=9809ce63-3ba9-4645-855e-2cc1fced1181&hsutk=20e73c2c01ae0c2d7d7755cb402af00a&pageId=5316083699\"  cta_dest_link=\"https://www.qt.io/download-qt-for-device-creation\"><img id=\"hs-cta-img-c80600ba-f2ea-45ed-97ef-6949c1c4c236\" class=\"hs-cta-img c-btn\" style=\"border-width: 0px; /*hs-extra-styles*/\" mce_noresize=\"1\" alt=\"Try Qt for free\" src=\"https://cdn2.hubspot.net/hubshot/17/12/13/e488b2e4-6ad2-4877-8321-0b4012f8a3b5.png\" /></a>","is_image":false,"placement_element_class":"hs-cta-c80600ba-f2ea-45ed-97ef-6949c1c4c236","raw_html":"<a id=\"cta_button_149513_643bd8f4-2c59-4c4c-ba1a-4aaa05b51086\" class=\"cta_button c-btn\" href=\"https://cta-service-cms2.hubspot.com/ctas/v2/public/cs/c/?cta_guid=643bd8f4-2c59-4c4c-ba1a-4aaa05b51086&placement_guid=c80600ba-f2ea-45ed-97ef-6949c1c4c236&portal_id=149513&canon=https%3A%2F%2Fwww.qt.io%2Fqt-features-libraries-apis-tools-and-ide%2F&redirect_url=APefjpGmlR1pYkJ4Ccy1tc-702nNO0nhmJwk7gBnziCVXmDGfoNh_qB0gvlXqFpUTOOWf57yAEVrImi9ZSoLbt2QZluy1tj-OKpLHxlW-6zA6CZwoH79oVDjmjDqqUBVXcXUH0k_lpaTrt3YddEsgApnhvXfKuQcv0Co3YE-XhjiFbEqDJp_Ln7B316TZWYAP7w3GSnrxsOYJdXO0WXChj_Hfb7thZrNM8Rep-YdQ166Qg0hvAc1_JScAucstvYf6QfOv5bUoDFa7cmDCJRTfqavczB2JR1igUf4FBTEhbPeklbBxADJJ9Y&click=9809ce63-3ba9-4645-855e-2cc1fced1181&hsutk=20e73c2c01ae0c2d7d7755cb402af00a&pageId=5316083699\"  style=\"/*hs-extra-styles*/\" cta_dest_link=\"https://www.qt.io/download-qt-for-device-creation\" title=\"Try Qt for free\"><span>Try Qt for free</span></a>"};
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
            window.hbspt && hbspt.cta && hbspt.cta.afterLoad && hbspt.cta.afterLoad('c80600ba-f2ea-45ed-97ef-6949c1c4c236');
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
    window._hsq.push(['trackCtaView', 'c80600ba-f2ea-45ed-97ef-6949c1c4c236', '643bd8f4-2c59-4c4c-ba1a-4aaa05b51086']);
}());
