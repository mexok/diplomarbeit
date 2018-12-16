(function() {

    var __hs_cta_json = {"css":"a#cta_button_149513_bf1b88c7-6db0-4cba-8155-071a2e3bbb17 {\n  cursor:pointer; \n}\na#cta_button_149513_bf1b88c7-6db0-4cba-8155-071a2e3bbb17:hover {\n}\na#cta_button_149513_bf1b88c7-6db0-4cba-8155-071a2e3bbb17:active, #cta_button_149513_bf1b88c7-6db0-4cba-8155-071a2e3bbb17:active:hover {\n}\n\n","image_html":"<a id=\"cta_button_149513_bf1b88c7-6db0-4cba-8155-071a2e3bbb17\" class=\"cta_button\" href=\"https://cta-service-cms2.hubspot.com/ctas/v2/public/cs/c/?cta_guid=bf1b88c7-6db0-4cba-8155-071a2e3bbb17&placement_guid=218c4d07-33f2-4bd3-91c6-be00365184a6&portal_id=149513&canon=https%3A%2F%2Fwww.qt.io%2Fqt-features-libraries-apis-tools-and-ide%2F&redirect_url=APefjpH0_Kg-XYdCqQJe3ocXAgO0tED7pAX0Gv_p2dbHM_QiohdT0P-mVzxz7LyP78CLQzjZ7e9t7caha-5b8ojIkotOiM1EdTXSdH5Zdi_Jj8zC-jwB9BTR_GMH4ycMV-sR0_CUYcWY6Kvy35xqln7aBdn4z8FsNcivHIPsqPKWa9vZMusf7_6SksKDtPyrLEMspvVH0CDnsNTsf7MWLZjhhaIb_El9jtAj_lX75MhtU9S9smRBJT_V-mpCazVvcpUH9Ict8BNVBnqdPLUozdmc-e8jNVA4BccrpS5Q5JmDVVabckE8do8&click=9adfe02d-4e4d-4523-bd4c-2f7977e5b702&hsutk=20e73c2c01ae0c2d7d7755cb402af00a&pageId=5316083699\"  target=\"_blank\"  cta_dest_link=\"https://doc.qt.io/qt-5/topics-app-development.html\"><img id=\"hs-cta-img-218c4d07-33f2-4bd3-91c6-be00365184a6\" class=\"hs-cta-img c-btn--small\" style=\"border-width: 0px; /*hs-extra-styles*/\" mce_noresize=\"1\" alt=\"Go to tools documentation\" src=\"https://cdn2.hubspot.net/hubshot/17/09/07/156829e8-1f6e-4330-a794-dd9bae387e65.png\" /></a>","is_image":false,"placement_element_class":"hs-cta-218c4d07-33f2-4bd3-91c6-be00365184a6","raw_html":"<a id=\"cta_button_149513_bf1b88c7-6db0-4cba-8155-071a2e3bbb17\" class=\"cta_button c-btn--small\" href=\"https://cta-service-cms2.hubspot.com/ctas/v2/public/cs/c/?cta_guid=bf1b88c7-6db0-4cba-8155-071a2e3bbb17&placement_guid=218c4d07-33f2-4bd3-91c6-be00365184a6&portal_id=149513&canon=https%3A%2F%2Fwww.qt.io%2Fqt-features-libraries-apis-tools-and-ide%2F&redirect_url=APefjpH0_Kg-XYdCqQJe3ocXAgO0tED7pAX0Gv_p2dbHM_QiohdT0P-mVzxz7LyP78CLQzjZ7e9t7caha-5b8ojIkotOiM1EdTXSdH5Zdi_Jj8zC-jwB9BTR_GMH4ycMV-sR0_CUYcWY6Kvy35xqln7aBdn4z8FsNcivHIPsqPKWa9vZMusf7_6SksKDtPyrLEMspvVH0CDnsNTsf7MWLZjhhaIb_El9jtAj_lX75MhtU9S9smRBJT_V-mpCazVvcpUH9Ict8BNVBnqdPLUozdmc-e8jNVA4BccrpS5Q5JmDVVabckE8do8&click=9adfe02d-4e4d-4523-bd4c-2f7977e5b702&hsutk=20e73c2c01ae0c2d7d7755cb402af00a&pageId=5316083699\" target=\"_blank\" style=\"/*hs-extra-styles*/\" cta_dest_link=\"https://doc.qt.io/qt-5/topics-app-development.html\" title=\"Go to tools documentation\">Go to tools documentation</a>"};
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
            window.hbspt && hbspt.cta && hbspt.cta.afterLoad && hbspt.cta.afterLoad('218c4d07-33f2-4bd3-91c6-be00365184a6');
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
    window._hsq.push(['trackCtaView', '218c4d07-33f2-4bd3-91c6-be00365184a6', 'bf1b88c7-6db0-4cba-8155-071a2e3bbb17']);
}());
