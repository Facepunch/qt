(: Name: fn-matches-26 :)
(: Description: Check for the correct behavior of ^ and $ in multi-line mode :)
(: This test case was motivated by the resolution of Bug Report 4543 :)


fn:matches("abcd&#x0a;defg&#x0a;", "^$", "m")