(function() {

    var __hs_cta_json = {"css":"a#cta_button_149513_bf8ed9d1-2973-4b1d-beaf-0787e72488b5 {\n  cursor:pointer; \n}\na#cta_button_149513_bf8ed9d1-2973-4b1d-beaf-0787e72488b5:hover {\n}\na#cta_button_149513_bf8ed9d1-2973-4b1d-beaf-0787e72488b5:active, #cta_button_149513_bf8ed9d1-2973-4b1d-beaf-0787e72488b5:active:hover {\n}\n\n","image_html":"<a id=\"cta_button_149513_bf8ed9d1-2973-4b1d-beaf-0787e72488b5\" class=\"cta_button\" href=\"https://cta-service-cms2.hubspot.com/ctas/v2/public/cs/c/?cta_guid=bf8ed9d1-2973-4b1d-beaf-0787e72488b5&placement_guid=d7620cba-0626-49ec-abc9-328eb83217d9&portal_id=149513&canon=https%3A%2F%2Fwww.qt.io%2Fwhat-is-qt%2F&redirect_url=APefjpFm7h6rqOYxgARuoN521PDFnykjduu1HXBVHeg3ghsZCKqjtT_xgFAEiSd8QT0iwaL7XX5ZEtrhRJ4MzGWihihiMUIamajZCYvOqgcyVuoRnliUtp95ogmj-Y_9A0TaSpK-7XBQdQur1C947TQ3v1d4777E0qdD7OT_Z1U9R7TDOKpQqMMag_un38mHjZPlJGb25NO-5Wv4DtJZsuxqeB5pFOLmJA&click=6b09c84a-564c-4842-b615-4dfe558be107&hsutk=20e73c2c01ae0c2d7d7755cb402af00a&pageId=5294071221\"  cta_dest_link=\"http://blog.qt.io/\"><img id=\"hs-cta-img-d7620cba-0626-49ec-abc9-328eb83217d9\" class=\"hs-cta-img c-btn--small\" style=\"border-width: 0px; /*hs-extra-styles*/\" mce_noresize=\"1\" alt=\"To the blog!\" src=\"https://cdn2.hubspot.net/hubshot/17/08/30/9db29666-90cc-4b63-a98d-24ab10555505.png\" /></a>","is_image":false,"placement_element_class":"hs-cta-d7620cba-0626-49ec-abc9-328eb83217d9","raw_html":"<a id=\"cta_button_149513_bf8ed9d1-2973-4b1d-beaf-0787e72488b5\" class=\"cta_button c-btn--small\" href=\"https://cta-service-cms2.hubspot.com/ctas/v2/public/cs/c/?cta_guid=bf8ed9d1-2973-4b1d-beaf-0787e72488b5&placement_guid=d7620cba-0626-49ec-abc9-328eb83217d9&portal_id=149513&canon=https%3A%2F%2Fwww.qt.io%2Fwhat-is-qt%2F&redirect_url=APefjpFm7h6rqOYxgARuoN521PDFnykjduu1HXBVHeg3ghsZCKqjtT_xgFAEiSd8QT0iwaL7XX5ZEtrhRJ4MzGWihihiMUIamajZCYvOqgcyVuoRnliUtp95ogmj-Y_9A0TaSpK-7XBQdQur1C947TQ3v1d4777E0qdD7OT_Z1U9R7TDOKpQqMMag_un38mHjZPlJGb25NO-5Wv4DtJZsuxqeB5pFOLmJA&click=6b09c84a-564c-4842-b615-4dfe558be107&hsutk=20e73c2c01ae0c2d7d7755cb402af00a&pageId=5294071221\"  style=\"/*hs-extra-styles*/\" cta_dest_link=\"http://blog.qt.io/\" title=\"To the blog!\">To the blog!</a>"};
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
            window.hbspt && hbspt.cta && hbspt.cta.afterLoad && hbspt.cta.afterLoad('d7620cba-0626-49ec-abc9-328eb83217d9');
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
    window._hsq.push(['trackCtaView', 'd7620cba-0626-49ec-abc9-328eb83217d9', 'bf8ed9d1-2973-4b1d-beaf-0787e72488b5']);
}());
