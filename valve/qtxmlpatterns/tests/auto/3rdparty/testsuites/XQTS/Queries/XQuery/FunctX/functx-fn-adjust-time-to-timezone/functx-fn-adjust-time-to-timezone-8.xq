(:**************************************************************:)
(: Test: functx-fn-adjust-time-to-timezone-8                                  :)
(: Written by: Priscilla Walmsley (Frans Englich is maintainer) :)
(: Date: 2008-05-16+02:00                                       :)
(:**************************************************************:)

declare namespace functx = "http://www.example.com/";
(adjust-time-to-timezone(
   xs:time('01:00:00-02:00')))