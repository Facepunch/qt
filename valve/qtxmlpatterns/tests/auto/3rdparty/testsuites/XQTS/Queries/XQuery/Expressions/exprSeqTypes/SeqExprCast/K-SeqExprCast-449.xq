(:*******************************************************:)
(: Test: K-SeqExprCast-449                               :)
(: Written by: Frans Englich                             :)
(: Date: 2007-11-22T11:31:21+01:00                       :)
(: Purpose: 'castable as' involving xs:float as source type and xs:float as target type should always evaluate to true. :)
(:*******************************************************:)
xs:float("3.4e5") castable as xs:float