(: Name: casthcds13 :)
(: Description: Simple test for casting a double as a string - XML Data Source :)
(: insert-start :)
import schema namespace atomic="http://www.w3.org/XQueryTest";
declare variable $input-context1 external;
(: insert-end :)


(($input-context1/atomic:root/atomic:double) cast as xs:string) eq xs:string("A String Function")