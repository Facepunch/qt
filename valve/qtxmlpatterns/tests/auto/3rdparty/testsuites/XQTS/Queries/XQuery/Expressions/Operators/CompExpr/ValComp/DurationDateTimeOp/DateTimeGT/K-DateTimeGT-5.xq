(:*******************************************************:)
(: Test: K-DateTimeGT-5                                  :)
(: Written by: Frans Englich                             :)
(: Date: 2007-11-22T11:31:21+01:00                       :)
(: Purpose: Simple test of 'ge' for xs:dateTime.         :)
(:*******************************************************:)
xs:dateTime("2004-07-13T23:01:04.12") ge
			   xs:dateTime("2004-07-12T23:01:04.12")