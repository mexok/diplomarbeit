var vmConsentCookieFinder = (function() {

    var CONSENT_COOKIES = ['euconsent', '_evidon_consent_cookie', 'oil_data'];

    function readCookie(cookieString, name) {
        var nameEQ = name + '=';
        var ca = (cookieString || '').split(';');
        for(var i=0; i < ca.length; i++) {
            var c = ca[i];
            while (c.charAt(0) === ' ') {
                c = c.substring(1,c.length);
            }
            if (c.indexOf(nameEQ) === 0) {
                return c.substring(nameEQ.length,c.length);
            }
        }
    }

    function findConsentCookie (cookieString) {

        try {
            for (var consentCookieIdx = 0; consentCookieIdx < CONSENT_COOKIES.length; consentCookieIdx++) {

                var cookieValue = readCookie(cookieString, CONSENT_COOKIES[consentCookieIdx]);
                if (cookieValue) {
                    return {
                        consentStr: cookieValue,
                        consentType: CONSENT_COOKIES[consentCookieIdx]
                    }
                }
            }
        } catch(error) {}
    }

    return {
        readCookie: readCookie,
        findConsentCookie: findConsentCookie
    };
}());

// Export for unit tests
if (typeof module !== 'undefined' && module.exports != null) {
    module.exports = vmConsentCookieFinder;
};
/**
 * Reload the go service with the consent parameter
 */
!function () {

    var consentObj = vmConsentCookieFinder.findConsentCookie(document.cookie);
    var consentStr = consentObj ? consentObj.consentStr : '';
    var consentType = consentObj ? consentObj.consentType : '';

    // build new /go url
    var goUrl = '//k.intellitxt.com/go/1/?ipid=93739&referer=https://www.techopedia.com/definition/26802/vendor-lock-in';
    goUrl += '&consentstr=' + consentStr + '&consenttype=' + consentType;

    var goScript = document.createElement('script');
    goScript.src = goUrl;

    var head = document.getElementsByTagName('head')[0];
    head.appendChild(goScript);

    if (consentObj) {
        console.log('VM: ReloadGo with consentStr: <' +
            consentObj.consentStr + '>' +
            'consentType: <' + consentObj.consentType + '>');
    } else {
        console.log('VM: ReloadGo - Consent cookie not found');
    }

}();


