(:*******************************************************:)
(:Test: maxnni2args-3                                     :)
(:Written By: Carmelo Montanez                            :)
(:Date: Fri Dec 10 10:15:48 GMT-05:00 2004                :)
(:Purpose: Evaluates The "max" function                  :)
(: with the arguments set as follows:                    :)
(:$arg1 = xs:nonNegativeInteger(upper bound)             :)
(:$arg2 = xs:nonNegativeInteger(lower bound)             :)
(:*******************************************************:)

fn:max((xs:nonNegativeInteger("999999999999999999"),xs:nonNegativeInteger("0")))