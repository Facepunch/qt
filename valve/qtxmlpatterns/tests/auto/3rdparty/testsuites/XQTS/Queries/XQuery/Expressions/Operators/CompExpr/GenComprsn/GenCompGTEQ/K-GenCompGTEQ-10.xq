(:*******************************************************:)
(: Test: K-GenCompGTEQ-10                                :)
(: Written by: Frans Englich                             :)
(: Date: 2007-11-22T11:31:21+01:00                       :)
(: Purpose: <= combined with count().                    :)
(:*******************************************************:)
1 <= count((1, 2, 3, timezone-from-time(current-time()), 4))