(:*******************************************************:)
(: Test: K-NumericEqual-42                               :)
(: Written by: Frans Englich                             :)
(: Date: 2007-11-22T11:31:21+01:00                       :)
(: Purpose: Test that fn:count combined with expressions that might disable compile time evaluations(optimization) as well as the 'eq' operator, is conformant. :)
(:*******************************************************:)
not(0 eq count((1, 2, timezone-from-time(current-time()))))