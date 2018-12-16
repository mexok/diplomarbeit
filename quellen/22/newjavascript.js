/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


typeof $.typeahead === 'function' && $.typeahead({
    input: ".js-typeahead",
    minLength: 1,
    maxItem: 15,
    order: "asc",
    hint: true,
    group: {
        key: "group",
        template: "{{group}} gefunden"
    },
    maxItemPerGroup: 5,
    backdrop: {
        "background-color": "#fff"
    },
    href: "{{url}}",
    display: ["group", "name"],
        template: "{{name}} <small style='color:#999;'>{{description}}</small>",
    emptyTemplate: 'Keine Ergebnisse für "{{query}}"',
    dynamic: true,
    source: {
        "Artikel": {
            display: "name",
            ajax: {
                url: "/api/searchIncremental/{{query}}",
                path: "data.Artikel"
            }
        },
        "Abkuerzung": {
            display: "name",
            ajax: {
                url: "/api/searchIncremental/{{query}}",
                path: "data.Abkuerzung"
            }
        },
        "Tag": {
            display: "name",
            ajax: {
                url: "/api/searchIncremental/{{query}}",
                path: "data.Tag"
            },
        }
    },
    callback: {
        onReady: function (node) {
            this.container.find('.' + this.options.selector.dropdownItem + '.group-ale a').trigger('click')
        },
        onDropdownFilter: function (node, query, filter, result) {
            console.log(query)
            console.log(filter)
            console.log(result)
        }
    },
    debug: true
});
