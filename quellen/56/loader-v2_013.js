(function() {

    var __hs_cta_json = {"css":"a#cta_button_149513_53a9a038-3db1-4601-8edf-1701fcf108e4 {\n  cursor:pointer; \n}\na#cta_button_149513_53a9a038-3db1-4601-8edf-1701fcf108e4:hover {\n}\na#cta_button_149513_53a9a038-3db1-4601-8edf-1701fcf108e4:active, #cta_button_149513_53a9a038-3db1-4601-8edf-1701fcf108e4:active:hover {\n}\n\n","image_html":"<a id=\"cta_button_149513_53a9a038-3db1-4601-8edf-1701fcf108e4\" class=\"cta_button\" href=\"https://cta-service-cms2.hubspot.com/ctas/v2/public/cs/c/?cta_guid=53a9a038-3db1-4601-8edf-1701fcf108e4&placement_guid=bd9b9b21-c5e0-4b3f-8cff-78de4115488b&portal_id=149513&canon=https%3A%2F%2Fwww.qt.io%2Fwhat-is-qt%2F&redirect_url=APefjpGmGTP6ybf_6v58wpHkfs5Dgalxy-j9dO58Pi7b_2mkoRbONXZT3VNu-jNMo09LWyLmuW3ETgk4nKf2qkvRPqF4H_M44nCVbtxdikH1WAndnxvmZndiReCUvEY80uBAeqZe3BVaDeLhz0m4Z7L8UOmnEgp8pcJIOH_eX3nsb6ibPZYRykkIVEBUCc53ulO2_6v_2MordxBAtQXO8B-Bgg8hPFugAA&click=36351218-9817-492b-b7af-5d3849c65888&hsutk=20e73c2c01ae0c2d7d7755cb402af00a&pageId=5294071221\"  target=\"_blank\"  cta_dest_link=\"https://forum.qt.io/\"><img id=\"hs-cta-img-bd9b9b21-c5e0-4b3f-8cff-78de4115488b\" class=\"hs-cta-img c-btn--small\" style=\"border-width: 0px; /*hs-extra-styles*/\" mce_noresize=\"1\" alt=\"Connect with the community\" src=\"https://cdn2.hubspot.net/hubshot/17/09/06/e927fb81-5baa-4d3c-a0db-f6c41b67a491.png\" /></a>","is_image":false,"placement_element_class":"hs-cta-bd9b9b21-c5e0-4b3f-8cff-78de4115488b","raw_html":"<a id=\"cta_button_149513_53a9a038-3db1-4601-8edf-1701fcf108e4\" class=\"cta_button c-btn--small\" href=\"https://cta-service-cms2.hubspot.com/ctas/v2/public/cs/c/?cta_guid=53a9a038-3db1-4601-8edf-1701fcf108e4&placement_guid=bd9b9b21-c5e0-4b3f-8cff-78de4115488b&portal_id=149513&canon=https%3A%2F%2Fwww.qt.io%2Fwhat-is-qt%2F&redirect_url=APefjpGmGTP6ybf_6v58wpHkfs5Dgalxy-j9dO58Pi7b_2mkoRbONXZT3VNu-jNMo09LWyLmuW3ETgk4nKf2qkvRPqF4H_M44nCVbtxdikH1WAndnxvmZndiReCUvEY80uBAeqZe3BVaDeLhz0m4Z7L8UOmnEgp8pcJIOH_eX3nsb6ibPZYRykkIVEBUCc53ulO2_6v_2MordxBAtQXO8B-Bgg8hPFugAA&click=36351218-9817-492b-b7af-5d3849c65888&hsutk=20e73c2c01ae0c2d7d7755cb402af00a&pageId=5294071221\" target=\"_blank\" style=\"/*hs-extra-styles*/\" cta_dest_link=\"https://forum.qt.io/\" title=\"Connect with the community\">Connect with the community</a>"};
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
            window.hbspt && hbspt.cta && hbspt.cta.afterLoad && hbspt.cta.afterLoad('bd9b9b21-c5e0-4b3f-8cff-78de4115488b');
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
    window._hsq.push(['trackCtaView', 'bd9b9b21-c5e0-4b3f-8cff-78de4115488b', '53a9a038-3db1-4601-8edf-1701fcf108e4']);
}());
