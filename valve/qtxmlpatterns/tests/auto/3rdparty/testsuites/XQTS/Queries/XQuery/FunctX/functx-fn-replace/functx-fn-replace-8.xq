(:**************************************************************:)
(: Test: functx-fn-replace-8                                  :)
(: Written by: Priscilla Walmsley (Frans Englich is maintainer) :)
(: Date: 2008-05-16+02:00                                       :)
(:**************************************************************:)

declare namespace functx = "http://www.example.com/";
(replace('Chapter', '(Chap)|(Chapter)', 'x'))
