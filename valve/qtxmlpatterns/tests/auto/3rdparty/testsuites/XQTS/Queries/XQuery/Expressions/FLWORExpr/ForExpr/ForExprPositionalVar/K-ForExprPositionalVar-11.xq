(:*******************************************************:)
(: Test: K-ForExprPositionalVar-11                       :)
(: Written by: Frans Englich                             :)
(: Date: 2007-11-22T11:31:21+01:00                       :)
(: Purpose: Verify that the position is properly computed for the empty sequence. :)
(:*******************************************************:)
empty(for $i at $p in () return $p)