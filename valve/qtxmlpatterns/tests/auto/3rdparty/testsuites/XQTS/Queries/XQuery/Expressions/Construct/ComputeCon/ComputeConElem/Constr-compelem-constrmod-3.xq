(: Name: Constr-compelem-constrmod-3 :)
(: Written by: Andreas Behm :)
(: Description: strip decimal type :)

declare construction strip;

(: insert-start :)
declare variable $input-context external;
(: insert-end :)

(element elem {xs:decimal(($input-context//decimal[1]))}) cast as xs:integer