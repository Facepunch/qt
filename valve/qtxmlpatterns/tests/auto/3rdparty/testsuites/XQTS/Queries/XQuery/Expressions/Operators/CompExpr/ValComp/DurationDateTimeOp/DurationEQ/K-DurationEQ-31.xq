(:*******************************************************:)
(: Test: K-DurationEQ-31                                 :)
(: Written by: Frans Englich                             :)
(: Date: 2007-11-22T11:31:21+01:00                       :)
(: Purpose: Test comparing xs:dayTimeDuration and xs:yearMonthDuration stressing value representations are normalized properly. :)
(:*******************************************************:)
xs:yearMonthDuration("P1M") ne xs:dayTimeDuration("P31D")