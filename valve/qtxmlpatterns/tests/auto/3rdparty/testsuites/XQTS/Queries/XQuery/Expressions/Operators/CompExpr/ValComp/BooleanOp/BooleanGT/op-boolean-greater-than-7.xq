(:*******************************************************:)
(:Test: op-boolean-greater-than-7                        :)
(:Written By: Carmelo Montanez                           :)
(:Date: June 15, 2005                                    :)
(:Purpose: Evaluates The "boolean-greater-than" function :)
(: with operands set to "not(false)", "false" respectively.:)
(: Use of gt operator.                                   :)
(:*******************************************************:)
 
fn:not(xs:boolean("false")) gt xs:boolean("false")