(:*******************************************************:)
(:Test: fn-string-join-10                                :)
(:Written By: Carmelo Montanez                           :)
(:Date: Fri June 24, 2005                                :)
(:Purpose: Evaluates The "string-join" function          :)
(: with the arguments set as follows:                    :)
(:$arg1 = (" ")                                          :)
(:$arg2 = " AAAAABBBBB". Use of count to avoid empty file:)
(:*******************************************************:)

fn:count(fn:string-join((" "),"AAAAABBBBB"))