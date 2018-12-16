(function() {

    var __hs_cta_json = {"css":"a#cta_button_149513_50a90e90-d3f3-425a-ab4d-bc2d9fbc585b {\n  cursor:pointer; \n}\na#cta_button_149513_50a90e90-d3f3-425a-ab4d-bc2d9fbc585b:hover {\n}\na#cta_button_149513_50a90e90-d3f3-425a-ab4d-bc2d9fbc585b:active, #cta_button_149513_50a90e90-d3f3-425a-ab4d-bc2d9fbc585b:active:hover {\n}\n\n","image_html":"<a id=\"cta_button_149513_50a90e90-d3f3-425a-ab4d-bc2d9fbc585b\" class=\"cta_button\" href=\"https://cta-service-cms2.hubspot.com/ctas/v2/public/cs/c/?cta_guid=50a90e90-d3f3-425a-ab4d-bc2d9fbc585b&placement_guid=850501fd-a535-47a0-9aaa-5638662b538d&portal_id=149513&canon=https%3A%2F%2Fwww.qt.io%2Fqt-features-libraries-apis-tools-and-ide%2F&redirect_url=APefjpEaTXNaswhBOroERCBvgwM4Lkm_-5zNoNuxRLDKbB7-skdbQLMJ1aZr45JNJeLGRSoKvPfje9zevvCplhFfBiwvVwh1sOLPUlc8p50oBa7VRLACxyiOV2yeMZU3EEF6JXIv2QOyuUGCbI3PxGRJ1DbMRVRKxgXFKQ59w94QyUAJBjdl3cT-e6zuTMVMtnsbKaYhKOVydvE8YWn-eisJNkTIirasmKV1yMYRt0qMPwnxLWHbWZS0Tq_9aEDsL7qRpNvYIrul&click=2f23ae0e-8edd-4d55-8970-21302d333e8d&hsutk=20e73c2c01ae0c2d7d7755cb402af00a&pageId=5316083699\"  cta_dest_link=\"https://www.qt.io/qt-training/\"><img id=\"hs-cta-img-850501fd-a535-47a0-9aaa-5638662b538d\" class=\"hs-cta-img c-btn\" style=\"border-width: 0px; /*hs-extra-styles*/\" mce_noresize=\"1\" alt=\"Qt Training\" src=\"https://cdn2.hubspot.net/hubshot/17/09/07/015694d3-d12f-4985-96ff-f455f1fba5db.png\" /></a>","is_image":false,"placement_element_class":"hs-cta-850501fd-a535-47a0-9aaa-5638662b538d","raw_html":"<a id=\"cta_button_149513_50a90e90-d3f3-425a-ab4d-bc2d9fbc585b\" class=\"cta_button c-btn\" href=\"https://cta-service-cms2.hubspot.com/ctas/v2/public/cs/c/?cta_guid=50a90e90-d3f3-425a-ab4d-bc2d9fbc585b&placement_guid=850501fd-a535-47a0-9aaa-5638662b538d&portal_id=149513&canon=https%3A%2F%2Fwww.qt.io%2Fqt-features-libraries-apis-tools-and-ide%2F&redirect_url=APefjpEaTXNaswhBOroERCBvgwM4Lkm_-5zNoNuxRLDKbB7-skdbQLMJ1aZr45JNJeLGRSoKvPfje9zevvCplhFfBiwvVwh1sOLPUlc8p50oBa7VRLACxyiOV2yeMZU3EEF6JXIv2QOyuUGCbI3PxGRJ1DbMRVRKxgXFKQ59w94QyUAJBjdl3cT-e6zuTMVMtnsbKaYhKOVydvE8YWn-eisJNkTIirasmKV1yMYRt0qMPwnxLWHbWZS0Tq_9aEDsL7qRpNvYIrul&click=2f23ae0e-8edd-4d55-8970-21302d333e8d&hsutk=20e73c2c01ae0c2d7d7755cb402af00a&pageId=5316083699\"  style=\"/*hs-extra-styles*/\" cta_dest_link=\"https://www.qt.io/qt-training/\" title=\"Qt Training\"><span>Qt Training</span></a>"};
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
            window.hbspt && hbspt.cta && hbspt.cta.afterLoad && hbspt.cta.afterLoad('850501fd-a535-47a0-9aaa-5638662b538d');
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
    window._hsq.push(['trackCtaView', '850501fd-a535-47a0-9aaa-5638662b538d', '50a90e90-d3f3-425a-ab4d-bc2d9fbc585b']);
}());
