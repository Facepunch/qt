(:*******************************************************:)
(: Test: K-SeqExprCast-523                               :)
(: Written by: Frans Englich                             :)
(: Date: 2007-11-22T11:31:21+01:00                       :)
(: Purpose: 'castable as' involving xs:double as source type and xs:boolean as target type should always evaluate to true. :)
(:*******************************************************:)
xs:double("3.3e3") castable as xs:boolean