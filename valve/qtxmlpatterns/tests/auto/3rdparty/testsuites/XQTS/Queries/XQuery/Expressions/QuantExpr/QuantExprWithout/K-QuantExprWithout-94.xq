(:*******************************************************:)
(: Test: K-QuantExprWithout-94                           :)
(: Written by: Frans Englich                             :)
(: Date: 2007-11-22T11:31:21+01:00                       :)
(: Purpose: It is a type error to try to extract the EBV value of two integers. :)
(:*******************************************************:)
every $i in (1, 2, 3) satisfies ($i, $i)