(:*******************************************************:)
(: Test: K-SeqSUMFunc-26                                 :)
(: Written by: Frans Englich                             :)
(: Date: 2007-11-22T11:31:23+01:00                       :)
(: Purpose: A test whose essence is: `sum((1, 2, 3, xs:anyURI("a string"), xs:double("NaN")), 3)`. :)
(:*******************************************************:)
sum((1, 2, 3, xs:anyURI("a string"), xs:double("NaN")), 3)