(:*******************************************************:)
(: Test: K2-DirectConElemContent-10                      :)
(: Written by: Frans Englich                             :)
(: Date: 2007-11-22T11:31:21+01:00                       :)
(: Purpose: Test that the typed value of comment nodes is correct. :)
(:*******************************************************:)
not(data(<!-- a comment -->) instance of xs:untypedAtomic)