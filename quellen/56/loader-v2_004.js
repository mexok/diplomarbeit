(function() {

    var __hs_cta_json = {"css":"a#cta_button_149513_993e64d0-b3e8-40cd-b32c-b5eb8bf05f0a {\n  cursor:pointer; \n}\na#cta_button_149513_993e64d0-b3e8-40cd-b32c-b5eb8bf05f0a:hover {\n}\na#cta_button_149513_993e64d0-b3e8-40cd-b32c-b5eb8bf05f0a:active, #cta_button_149513_993e64d0-b3e8-40cd-b32c-b5eb8bf05f0a:active:hover {\n}\n\n","image_html":"<a id=\"cta_button_149513_993e64d0-b3e8-40cd-b32c-b5eb8bf05f0a\" class=\"cta_button\" href=\"https://cta-service-cms2.hubspot.com/ctas/v2/public/cs/c/?cta_guid=993e64d0-b3e8-40cd-b32c-b5eb8bf05f0a&placement_guid=5da5e2cd-9eb3-4dc2-a917-d7419c6adca8&portal_id=149513&canon=https%3A%2F%2Fwww.qt.io%2Fwhat-is-qt%2F&redirect_url=APefjpF7hV18tMcpxASUkOLV0pl53dCdviYRx3U8ZVKGdhSzLnZ93TqqRYbRJIN1cUG3WU4n9ciYHRNf1INMc2NtxD08NZ3ndUrcF_RmnTIBMkjUNpIFgEQcCfNAG0Qh9wJbLIAw-og5aRxmTbPbSN8kIa_8IAzGVguOLurL39e0efSoM9lUCtcoQA2PrEBGsUUgdbXdI8_Pr86ivUPTjNgOnzE5sDZ3AvgPbxThuUTVYBfK1elE7NE_Hq8PKK8rTi6vuuz7pfs9&click=2a9cbef5-117e-41b7-8a7b-b46729b9f9fb&hsutk=20e73c2c01ae0c2d7d7755cb402af00a&pageId=5294071221\"  target=\"_blank\"  cta_dest_link=\"http://doc.qt.io/qt-5/supported-platforms.html\"><img id=\"hs-cta-img-5da5e2cd-9eb3-4dc2-a917-d7419c6adca8\" class=\"hs-cta-img c-btn--small\" style=\"border-width: 0px; /*hs-extra-styles*/\" mce_noresize=\"1\" alt=\"Supported Platforms\" src=\"https://cdn2.hubspot.net/hubshot/17/09/06/d6c7ec8e-120a-4fee-95c2-1f69d0dfa34e.png\" /></a>","is_image":false,"placement_element_class":"hs-cta-5da5e2cd-9eb3-4dc2-a917-d7419c6adca8","raw_html":"<a id=\"cta_button_149513_993e64d0-b3e8-40cd-b32c-b5eb8bf05f0a\" class=\"cta_button c-btn--small\" href=\"https://cta-service-cms2.hubspot.com/ctas/v2/public/cs/c/?cta_guid=993e64d0-b3e8-40cd-b32c-b5eb8bf05f0a&placement_guid=5da5e2cd-9eb3-4dc2-a917-d7419c6adca8&portal_id=149513&canon=https%3A%2F%2Fwww.qt.io%2Fwhat-is-qt%2F&redirect_url=APefjpF7hV18tMcpxASUkOLV0pl53dCdviYRx3U8ZVKGdhSzLnZ93TqqRYbRJIN1cUG3WU4n9ciYHRNf1INMc2NtxD08NZ3ndUrcF_RmnTIBMkjUNpIFgEQcCfNAG0Qh9wJbLIAw-og5aRxmTbPbSN8kIa_8IAzGVguOLurL39e0efSoM9lUCtcoQA2PrEBGsUUgdbXdI8_Pr86ivUPTjNgOnzE5sDZ3AvgPbxThuUTVYBfK1elE7NE_Hq8PKK8rTi6vuuz7pfs9&click=2a9cbef5-117e-41b7-8a7b-b46729b9f9fb&hsutk=20e73c2c01ae0c2d7d7755cb402af00a&pageId=5294071221\" target=\"_blank\" style=\"/*hs-extra-styles*/\" cta_dest_link=\"http://doc.qt.io/qt-5/supported-platforms.html\" title=\"Supported Platforms\">Supported Platforms</a>"};
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
            window.hbspt && hbspt.cta && hbspt.cta.afterLoad && hbspt.cta.afterLoad('5da5e2cd-9eb3-4dc2-a917-d7419c6adca8');
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
    window._hsq.push(['trackCtaView', '5da5e2cd-9eb3-4dc2-a917-d7419c6adca8', '993e64d0-b3e8-40cd-b32c-b5eb8bf05f0a']);
}());
