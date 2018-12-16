(function() {

    var __hs_cta_json = {"css":"a#cta_button_149513_22906740-7938-4f82-8554-1487a803323d {\n  cursor:pointer; \n}\na#cta_button_149513_22906740-7938-4f82-8554-1487a803323d:hover {\n}\na#cta_button_149513_22906740-7938-4f82-8554-1487a803323d:active, #cta_button_149513_22906740-7938-4f82-8554-1487a803323d:active:hover {\n}\n\n","image_html":"<a id=\"cta_button_149513_22906740-7938-4f82-8554-1487a803323d\" class=\"cta_button\" href=\"https://cta-service-cms2.hubspot.com/ctas/v2/public/cs/c/?cta_guid=22906740-7938-4f82-8554-1487a803323d&placement_guid=597c8215-4e88-4e0e-8fe9-189eb85c2ecf&portal_id=149513&canon=https%3A%2F%2Fwww.qt.io%2Fqt-features-libraries-apis-tools-and-ide%2F&redirect_url=APefjpF1ltlb8jHbTdc67lCOdRZw7Krxwjxbl0t-MQahRoRsx5btgS1xvwYNHTCk3Esk9YoOrwY-iJwWePWZMy7_dop_R4y2tmUjxamLXCGuS1wBfLskV1mag-FG01ta5NFMa7ZVF31DWUG0-YfWYpiOCrzDmAAh1jJXz2topi9Bj-BYlOXUZYZfSFe1xFGBIjO-LMzKViyjfjM1-wFs7ADdFRBlHO6iFCvQ4BMwBP0WT3MhkVF2S2roaxmIinpZayDUphu9XnQt_FLV12cuAqVoXLW7NxQnbUXn_G1Tv6OLP8mXq4FHVfY&click=28847305-60f8-4a12-8dd3-32b2d31ef6a3&hsutk=20e73c2c01ae0c2d7d7755cb402af00a&pageId=5316083699\"  target=\"_blank\"  cta_dest_link=\"http://doc-snapshots.qt.io/qt5-5.9/qtmultimedia-index.html\"><img id=\"hs-cta-img-597c8215-4e88-4e0e-8fe9-189eb85c2ecf\" class=\"hs-cta-img c-btn--small\" style=\"border-width: 0px; /*hs-extra-styles*/\" mce_noresize=\"1\" alt=\"Technical details\" src=\"https://cdn2.hubspot.net/hubshot/17/09/07/a256f49f-4617-4cb1-9c42-1bd06401e28c.png\" /></a>","is_image":false,"placement_element_class":"hs-cta-597c8215-4e88-4e0e-8fe9-189eb85c2ecf","raw_html":"<a id=\"cta_button_149513_22906740-7938-4f82-8554-1487a803323d\" class=\"cta_button c-btn--small\" href=\"https://cta-service-cms2.hubspot.com/ctas/v2/public/cs/c/?cta_guid=22906740-7938-4f82-8554-1487a803323d&placement_guid=597c8215-4e88-4e0e-8fe9-189eb85c2ecf&portal_id=149513&canon=https%3A%2F%2Fwww.qt.io%2Fqt-features-libraries-apis-tools-and-ide%2F&redirect_url=APefjpF1ltlb8jHbTdc67lCOdRZw7Krxwjxbl0t-MQahRoRsx5btgS1xvwYNHTCk3Esk9YoOrwY-iJwWePWZMy7_dop_R4y2tmUjxamLXCGuS1wBfLskV1mag-FG01ta5NFMa7ZVF31DWUG0-YfWYpiOCrzDmAAh1jJXz2topi9Bj-BYlOXUZYZfSFe1xFGBIjO-LMzKViyjfjM1-wFs7ADdFRBlHO6iFCvQ4BMwBP0WT3MhkVF2S2roaxmIinpZayDUphu9XnQt_FLV12cuAqVoXLW7NxQnbUXn_G1Tv6OLP8mXq4FHVfY&click=28847305-60f8-4a12-8dd3-32b2d31ef6a3&hsutk=20e73c2c01ae0c2d7d7755cb402af00a&pageId=5316083699\" target=\"_blank\" style=\"/*hs-extra-styles*/\" cta_dest_link=\"http://doc-snapshots.qt.io/qt5-5.9/qtmultimedia-index.html\" title=\"Technical details\">Technical details</a>"};
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
            window.hbspt && hbspt.cta && hbspt.cta.afterLoad && hbspt.cta.afterLoad('597c8215-4e88-4e0e-8fe9-189eb85c2ecf');
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
    window._hsq.push(['trackCtaView', '597c8215-4e88-4e0e-8fe9-189eb85c2ecf', '22906740-7938-4f82-8554-1487a803323d']);
}());
