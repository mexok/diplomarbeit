(function() {

    var __hs_cta_json = {"css":"a#cta_button_149513_7d0398ef-4bff-43c4-bf1f-020c9a424531 {\n  cursor:pointer; \n}\na#cta_button_149513_7d0398ef-4bff-43c4-bf1f-020c9a424531:hover {\n}\na#cta_button_149513_7d0398ef-4bff-43c4-bf1f-020c9a424531:active, #cta_button_149513_7d0398ef-4bff-43c4-bf1f-020c9a424531:active:hover {\n}\n\n","image_html":"<a id=\"cta_button_149513_7d0398ef-4bff-43c4-bf1f-020c9a424531\" class=\"cta_button\" href=\"https://cta-service-cms2.hubspot.com/ctas/v2/public/cs/c/?cta_guid=7d0398ef-4bff-43c4-bf1f-020c9a424531&placement_guid=217cd8ea-e00d-4835-adef-da895aed85f6&portal_id=149513&canon=https%3A%2F%2Fwww.qt.io%2Fwhat-is-qt%2F&redirect_url=APefjpFpceKE29UWABAxZicCoi_dXaUuNhU5m0crds3eucwzYJFnGS_0aNEL_eS-y8Tg2r3U9ZwRAPxHCZAsbK2s8ZgpXVKsF4krSt36fqANDgi2vLRa7V2jkcuxzy48dMezj4U3-qlRFi2uJaXIhC9yUqME9n-dS9WnGVrroRDo5_4eX_pTGMBjC0tDfAJ1Y5Ptvg6rry0LFKRjYyDo84i30vzyaG6Ppez5LmKZ1s0lG2KXPk6LFug&click=1323e732-1325-45bd-a0b1-fd33b2b37f7c&hsutk=20e73c2c01ae0c2d7d7755cb402af00a&pageId=5294071221\"  cta_dest_link=\"https://www.qt.io/tableau-built-with-qt\"><img id=\"hs-cta-img-217cd8ea-e00d-4835-adef-da895aed85f6\" class=\"hs-cta-img c-btn--small\" style=\"border-width: 0px; /*hs-extra-styles*/\" mce_noresize=\"1\" alt=\"Adam&#39;s full story\" src=\"https://cdn2.hubspot.net/hubshot/18/03/02/b54f9406-ce03-4a3d-9810-aa3564f3877e.png\" /></a>","is_image":false,"placement_element_class":"hs-cta-217cd8ea-e00d-4835-adef-da895aed85f6","raw_html":"<a id=\"cta_button_149513_7d0398ef-4bff-43c4-bf1f-020c9a424531\" class=\"cta_button c-btn--small\" href=\"https://cta-service-cms2.hubspot.com/ctas/v2/public/cs/c/?cta_guid=7d0398ef-4bff-43c4-bf1f-020c9a424531&placement_guid=217cd8ea-e00d-4835-adef-da895aed85f6&portal_id=149513&canon=https%3A%2F%2Fwww.qt.io%2Fwhat-is-qt%2F&redirect_url=APefjpFpceKE29UWABAxZicCoi_dXaUuNhU5m0crds3eucwzYJFnGS_0aNEL_eS-y8Tg2r3U9ZwRAPxHCZAsbK2s8ZgpXVKsF4krSt36fqANDgi2vLRa7V2jkcuxzy48dMezj4U3-qlRFi2uJaXIhC9yUqME9n-dS9WnGVrroRDo5_4eX_pTGMBjC0tDfAJ1Y5Ptvg6rry0LFKRjYyDo84i30vzyaG6Ppez5LmKZ1s0lG2KXPk6LFug&click=1323e732-1325-45bd-a0b1-fd33b2b37f7c&hsutk=20e73c2c01ae0c2d7d7755cb402af00a&pageId=5294071221\"  style=\"/*hs-extra-styles*/\" cta_dest_link=\"https://www.qt.io/tableau-built-with-qt\" title=\"Adam&#39;s full story\">Adam's full story</a>"};
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
            window.hbspt && hbspt.cta && hbspt.cta.afterLoad && hbspt.cta.afterLoad('217cd8ea-e00d-4835-adef-da895aed85f6');
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
    window._hsq.push(['trackCtaView', '217cd8ea-e00d-4835-adef-da895aed85f6', '7d0398ef-4bff-43c4-bf1f-020c9a424531']);
}());
