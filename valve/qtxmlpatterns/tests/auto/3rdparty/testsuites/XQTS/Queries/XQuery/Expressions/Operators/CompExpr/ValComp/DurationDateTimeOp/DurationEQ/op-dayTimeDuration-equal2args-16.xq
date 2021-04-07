(:*******************************************************:)
(:Test: op-dayTimeDuration-equal2args-16                 :)
(:Written By: Carmelo Montanez                           :)
(:Date: June 3, 2005                                     :)
(:Purpose: Evaluates The "op:dayTimeDuration-equal" operator (ge) :)
(: with the arguments set as follows:                    :)
(:$arg1 = xs:dayTimeDuration(lower bound)               :)
(:$arg2 = xs:dayTimeDuration(lower bound)               :)
(:*******************************************************:)

xs:dayTimeDuration("P0DT0H0M0S") ge xs:dayTimeDuration("P0DT0H0M0S")