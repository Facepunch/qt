(:*******************************************************:)
(:Test: op-subtract-yearMonthDurations-3                 :)
(:Written By: Carmelo Montanez                           :)
(:Date: June 28, 2005                                    :)
(:Purpose: Evaluates The "subtract-yearMonthDurations" function as :)
(:part of a boolean expression (or operator) and the "fn:boolean" function. :)
(: Apply "fn:string" function to account for new EBV.     :)
(:*******************************************************:)
 
fn:string(xs:yearMonthDuration("P20Y10M") - xs:yearMonthDuration("P19Y10M")) or fn:false()