(:*******************************************************:)
(: Test: K-SeqExprCast-1373                              :)
(: Written by: Frans Englich                             :)
(: Date: 2007-11-22T11:31:22+01:00                       :)
(: Purpose: 'castable as' involving xs:anyURI as source type and xs:untypedAtomic as target type should always evaluate to true. :)
(:*******************************************************:)
xs:anyURI("http://www.example.com/an/arbitrary/URI.ext") castable as xs:untypedAtomic