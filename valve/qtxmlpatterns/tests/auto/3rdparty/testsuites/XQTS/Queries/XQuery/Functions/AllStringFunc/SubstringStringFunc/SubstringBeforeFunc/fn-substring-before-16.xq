(:*******************************************************:)
(:Test: fn-substring-before-16                           :)
(:Written By: Carmelo Montanez                           :)
(:Date: Fri May 27, 2005                                 :)
(:Purpose: Evaluates The "substring-before" function     :)
(: with the arguments set as follows:                    :)
(:$arg1 = "a"                                            :)
(:$arg2 = "A"                                            :)
(:*******************************************************:)

fn:count(fn:substring-before("a","A"))