(:*******************************************************:)
(: Test: K-SeqExprCast-910                               :)
(: Written by: Frans Englich                             :)
(: Date: 2007-11-22T11:31:22+01:00                       :)
(: Purpose: Casting from xs:date to xs:double isn't allowed. :)
(:*******************************************************:)
xs:date("2004-10-13") cast as xs:double