(function() {

    var __hs_cta_json = {"css":"a#cta_button_149513_fdd686d1-7d09-4707-89a7-417c5c297620 {\n  cursor:pointer; \n}\na#cta_button_149513_fdd686d1-7d09-4707-89a7-417c5c297620:hover {\n}\na#cta_button_149513_fdd686d1-7d09-4707-89a7-417c5c297620:active, #cta_button_149513_fdd686d1-7d09-4707-89a7-417c5c297620:active:hover {\n}\n\n","image_html":"<a id=\"cta_button_149513_fdd686d1-7d09-4707-89a7-417c5c297620\" class=\"cta_button\" href=\"https://cta-service-cms2.hubspot.com/ctas/v2/public/cs/c/?cta_guid=fdd686d1-7d09-4707-89a7-417c5c297620&placement_guid=86310de7-fb82-4a3f-b320-045252048660&portal_id=149513&canon=https%3A%2F%2Fwww.qt.io%2Fqt-features-libraries-apis-tools-and-ide%2F&redirect_url=APefjpEjgiGHDomWRLWYVRGSB-BcM8uXV_aDWOXRYXhvEXUPB3IlN56WzrwgSY-CaggzL5MDbmIunFAILhgq8muurS8osdkwjcY19AelEwrLLYP9uHPCZXSl-bjlGHR4eZ7wZB64K7hGe2K0t-A8iTtHnn-Vz-5WJgTuzzMcHqyjwgzQEC5xrtxwbkNiqrjggeSvnjc8MACTct2MhPDkc1Ig_M_eITdD3xgeDuTo6odYlIByH2F19J8ijSwg7JggO2gdNpGC0MSyE1Vn3u1p73Pw1TASjK2zBQ&click=a1317be0-a0ae-4455-93bb-431e2a8553de&hsutk=20e73c2c01ae0c2d7d7755cb402af00a&pageId=5316083699\"  target=\"_blank\"  cta_dest_link=\"https://doc.qt.io/qt-5/qthelp-framework.html\"><img id=\"hs-cta-img-86310de7-fb82-4a3f-b320-045252048660\" class=\"hs-cta-img c-btn--small\" style=\"border-width: 0px; /*hs-extra-styles*/\" mce_noresize=\"1\" alt=\"Technical details\" src=\"https://cdn2.hubspot.net/hubshot/17/09/07/670339ba-a5f1-4f89-b7a7-31ec4491147f.png\" /></a>","is_image":false,"placement_element_class":"hs-cta-86310de7-fb82-4a3f-b320-045252048660","raw_html":"<a id=\"cta_button_149513_fdd686d1-7d09-4707-89a7-417c5c297620\" class=\"cta_button c-btn--small\" href=\"https://cta-service-cms2.hubspot.com/ctas/v2/public/cs/c/?cta_guid=fdd686d1-7d09-4707-89a7-417c5c297620&placement_guid=86310de7-fb82-4a3f-b320-045252048660&portal_id=149513&canon=https%3A%2F%2Fwww.qt.io%2Fqt-features-libraries-apis-tools-and-ide%2F&redirect_url=APefjpEjgiGHDomWRLWYVRGSB-BcM8uXV_aDWOXRYXhvEXUPB3IlN56WzrwgSY-CaggzL5MDbmIunFAILhgq8muurS8osdkwjcY19AelEwrLLYP9uHPCZXSl-bjlGHR4eZ7wZB64K7hGe2K0t-A8iTtHnn-Vz-5WJgTuzzMcHqyjwgzQEC5xrtxwbkNiqrjggeSvnjc8MACTct2MhPDkc1Ig_M_eITdD3xgeDuTo6odYlIByH2F19J8ijSwg7JggO2gdNpGC0MSyE1Vn3u1p73Pw1TASjK2zBQ&click=a1317be0-a0ae-4455-93bb-431e2a8553de&hsutk=20e73c2c01ae0c2d7d7755cb402af00a&pageId=5316083699\" target=\"_blank\" style=\"/*hs-extra-styles*/\" cta_dest_link=\"https://doc.qt.io/qt-5/qthelp-framework.html\" title=\"Technical details\">Technical details</a>"};
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
            window.hbspt && hbspt.cta && hbspt.cta.afterLoad && hbspt.cta.afterLoad('86310de7-fb82-4a3f-b320-045252048660');
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
    window._hsq.push(['trackCtaView', '86310de7-fb82-4a3f-b320-045252048660', 'fdd686d1-7d09-4707-89a7-417c5c297620']);
}());
