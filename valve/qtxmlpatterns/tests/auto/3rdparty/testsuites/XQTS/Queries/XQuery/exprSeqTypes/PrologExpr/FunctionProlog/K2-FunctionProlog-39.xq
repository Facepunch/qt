(:*******************************************************:)
(: Test: K2-FunctionProlog-39                            :)
(: Written by: Frans Englich                             :)
(: Date: 2007-11-22T11:31:21+01:00                       :)
(: Purpose: Use complex real-world case for function calls, with automatic conversion not needed. :)
(:*******************************************************:)
declare variable $A:=(<A>{local:functionA()}</A>);
declare function local:functionA() as element()
{
<input>testing ...</input>
};

declare function local:functionB ( ) as xs:string
{
xs:string($A)
};

local:functionB()