(:*******************************************************:)
(: Test: VarDecl007.xq          :)
(: Written By: Ravindranath Chennoju                     :)
(: Date: Wed Jun 29 14:28:57 2005                        :)
(: Purpose - Variable with no type definition            :)
(:*******************************************************:)

declare variable $x := "a "" or a ' delimits a string literal" ; 
$x
