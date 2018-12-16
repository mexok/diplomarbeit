(function() {

    var __hs_cta_json = {"css":"a#cta_button_149513_2768e86f-8725-4c21-94f4-05ca37269560 {\n  cursor:pointer; \n}\na#cta_button_149513_2768e86f-8725-4c21-94f4-05ca37269560:hover {\n}\na#cta_button_149513_2768e86f-8725-4c21-94f4-05ca37269560:active, #cta_button_149513_2768e86f-8725-4c21-94f4-05ca37269560:active:hover {\n}\n\n","image_html":"<a id=\"cta_button_149513_2768e86f-8725-4c21-94f4-05ca37269560\" class=\"cta_button\" href=\"https://cta-service-cms2.hubspot.com/ctas/v2/public/cs/c/?cta_guid=2768e86f-8725-4c21-94f4-05ca37269560&placement_guid=43d456ba-054d-4717-a4fd-07113604eb05&portal_id=149513&canon=https%3A%2F%2Fwww.qt.io%2Fqt-features-libraries-apis-tools-and-ide%2F&redirect_url=APefjpHGgRu7K8pB2-Ag5U-ISc0JYFSsBbciWAj7wlCd22HXSt5mAiaK-LhFKODi9zLxeujCuiY2bH6ByUj-saPoiqmGpi3dz3L11daSnqae6wBCAbnOYPX0EaKQp8pLeoaCpC_yZ2yTMMUYGUou0kMUbqkftZHIMDK-29tz3YkPvfE8rIpPD32y3byLDcECPu0tdXP1K6TGqr6yrNwRKA7DurPWJQU_O3hXrokVNYoO9fgQM2QOirI3ltFAb_F-G9MOMgHATe3Z&click=7627c42f-5e00-4e3d-a652-5eb74d9b4a67&hsutk=20e73c2c01ae0c2d7d7755cb402af00a&pageId=5316083699\"  cta_dest_link=\"https://www.qt.io/contact-us/\"><img id=\"hs-cta-img-43d456ba-054d-4717-a4fd-07113604eb05\" class=\"hs-cta-img c-btn\" style=\"border-width: 0px; /*hs-extra-styles*/\" mce_noresize=\"1\" alt=\"Contact us\" src=\"https://cdn2.hubspot.net/hubshot/17/09/07/b9797d7c-b117-46e7-860f-7df31e87ba49.png\" /></a>","is_image":false,"placement_element_class":"hs-cta-43d456ba-054d-4717-a4fd-07113604eb05","raw_html":"<a id=\"cta_button_149513_2768e86f-8725-4c21-94f4-05ca37269560\" class=\"cta_button c-btn\" href=\"https://cta-service-cms2.hubspot.com/ctas/v2/public/cs/c/?cta_guid=2768e86f-8725-4c21-94f4-05ca37269560&placement_guid=43d456ba-054d-4717-a4fd-07113604eb05&portal_id=149513&canon=https%3A%2F%2Fwww.qt.io%2Fqt-features-libraries-apis-tools-and-ide%2F&redirect_url=APefjpHGgRu7K8pB2-Ag5U-ISc0JYFSsBbciWAj7wlCd22HXSt5mAiaK-LhFKODi9zLxeujCuiY2bH6ByUj-saPoiqmGpi3dz3L11daSnqae6wBCAbnOYPX0EaKQp8pLeoaCpC_yZ2yTMMUYGUou0kMUbqkftZHIMDK-29tz3YkPvfE8rIpPD32y3byLDcECPu0tdXP1K6TGqr6yrNwRKA7DurPWJQU_O3hXrokVNYoO9fgQM2QOirI3ltFAb_F-G9MOMgHATe3Z&click=7627c42f-5e00-4e3d-a652-5eb74d9b4a67&hsutk=20e73c2c01ae0c2d7d7755cb402af00a&pageId=5316083699\"  style=\"/*hs-extra-styles*/\" cta_dest_link=\"https://www.qt.io/contact-us/\" title=\"Contact us\"><span>Contact us</span></a>"};
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
            window.hbspt && hbspt.cta && hbspt.cta.afterLoad && hbspt.cta.afterLoad('43d456ba-054d-4717-a4fd-07113604eb05');
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
    window._hsq.push(['trackCtaView', '43d456ba-054d-4717-a4fd-07113604eb05', '2768e86f-8725-4c21-94f4-05ca37269560']);
}());
