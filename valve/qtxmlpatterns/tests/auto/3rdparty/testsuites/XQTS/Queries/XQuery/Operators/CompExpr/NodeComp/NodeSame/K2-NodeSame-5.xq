(:*******************************************************:)
(: Test: K2-NodeSame-5                                   :)
(: Written by: Frans Englich                             :)
(: Date: 2007-11-22T11:31:21+01:00                       :)
(: Purpose: exactly-one() to is, that fails. Inferrence may conclude that it will always evaluate to false, so that is valid as well. :)
(:*******************************************************:)
empty(exactly-one(<e/>/*) is exactly-one(<e/>/*))