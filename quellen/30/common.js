function htmlEncode(n){return $("<div/>").text(n).html()}function recordDownload(n,t){var i=function(){ga("send","event","Download",n,t)};typeof mscc=="undefined"||mscc.hasConsent()?i():postCookieConsentTasks.push(i)}function onCookieConsentTasks(){for(LoadAnalytics(!1),i=0;i<postCookieConsentTasks.length;i++)postCookieConsentTasks[i]()}$(function(){if($('[data-toggle="tooltip"]').tooltip({trigger:"hover"}),typeof mscc!="undefined"&&!mscc.hasConsent()){mscc.on("consent",onCookieConsentTasks);$(document).click(function(){mscc.setConsent()})}});var postCookieConsentTasks=[];