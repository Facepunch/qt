(:*******************************************************:)
(: Test: K-Literals-6                                    :)
(: Written by: Frans Englich                             :)
(: Date: 2007-11-22T11:31:20+01:00                       :)
(: Purpose: '"fo""""' is a valid string literal.         :)
(:*******************************************************:)
"fo""o" eq concat("fo", """", "o")