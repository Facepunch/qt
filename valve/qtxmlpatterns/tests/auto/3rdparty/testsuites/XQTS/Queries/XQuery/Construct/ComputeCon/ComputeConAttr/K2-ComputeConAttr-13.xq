(:*******************************************************:)
(: Test: K2-ComputeConAttr-13                            :)
(: Written by: Frans Englich                             :)
(: Date: 2007-11-22T11:31:21+01:00                       :)
(: Purpose: Ensure XQTY0024 is issued when content appears before computed attributes. :)
(:*******************************************************:)
<foo >
	<doo/>
	{attribute name {"content"}}
</foo>