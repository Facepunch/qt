(:*******************************************************:)
(: Test: K-SeqExprCast-166                               :)
(: Written by: Frans Englich                             :)
(: Date: 2007-11-22T11:31:21+01:00                       :)
(: Purpose: Simple test of casting xs:yearMonthDuration to xs:duration. :)
(:*******************************************************:)

			xs:string(xs:duration(xs:yearMonthDuration("P543Y456M")))
			eq "P581Y"