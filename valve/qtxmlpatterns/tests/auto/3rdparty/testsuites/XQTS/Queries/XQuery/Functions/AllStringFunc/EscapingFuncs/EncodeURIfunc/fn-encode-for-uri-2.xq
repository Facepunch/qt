(: Name: fn-encode-for-uri-2 :)
(: Description: Examines that fn-encode-for-uri function does escape the "#" symbol. :)

(: insert-start :)
declare variable $input-context1 external;
(: insert-end :)

(fn:encode-for-uri("examples#example"))