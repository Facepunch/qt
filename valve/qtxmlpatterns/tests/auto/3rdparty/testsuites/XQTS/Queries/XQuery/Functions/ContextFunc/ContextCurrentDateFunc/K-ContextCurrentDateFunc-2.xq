(:*******************************************************:)
(: Test: K-ContextCurrentDateFunc-2                      :)
(: Written by: Frans Englich                             :)
(: Date: 2007-11-22T11:31:23+01:00                       :)
(: Purpose: Test that the Dynamic Context property 'current dateTime' when presented as a xs:date is stable during execution. :)
(:*******************************************************:)
current-date() eq current-date()