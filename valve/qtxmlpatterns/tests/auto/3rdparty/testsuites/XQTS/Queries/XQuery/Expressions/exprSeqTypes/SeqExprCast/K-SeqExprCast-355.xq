(:*******************************************************:)
(: Test: K-SeqExprCast-355                               :)
(: Written by: Frans Englich                             :)
(: Date: 2007-11-22T11:31:21+01:00                       :)
(: Purpose: '21:01:60' is an invalid lexical representation for xs:time; seconds part can never be larger than 59. :)
(:*******************************************************:)
xs:time("21:01:60")