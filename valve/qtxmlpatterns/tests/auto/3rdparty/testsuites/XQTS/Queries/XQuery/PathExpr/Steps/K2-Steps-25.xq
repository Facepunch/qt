(:*******************************************************:)
(: Test: K2-Steps-25                                     :)
(: Written by: Frans Englich                             :)
(: Date: 2007-11-22T11:31:21+01:00                       :)
(: Purpose: Tricky combination of focuses and function calls(#3). :)
(:*******************************************************:)
declare variable $root :=
<root>
    <b d=""/>
    <c>
        <c d=""/>
        <c/>
    </c>
</root>;

declare function local:function($object)
{
    $root/b[@d = $object/@d]
};

$root//local:function(c)
