(:*******************************************************:)
(: Test: K-WhereExpr-4                                   :)
(: Written by: Frans Englich                             :)
(: Date: 2007-11-22T11:31:21+01:00                       :)
(: Purpose: A for/where expression combined with fn:count(). :)
(:*******************************************************:)
for $i in 1 where count(($i, 2, timezone-from-time(current-time()))) return true()