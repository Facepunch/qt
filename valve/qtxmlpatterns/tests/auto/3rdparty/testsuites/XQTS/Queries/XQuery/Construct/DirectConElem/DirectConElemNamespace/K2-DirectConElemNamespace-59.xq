(:*******************************************************:)
(: Test: K2-DirectConElemNamespace-59                    :)
(: Written by: Frans Englich                             :)
(: Date: 2007-11-22T11:31:21+01:00                       :)
(: Purpose: Use the {}-escape mechanism.                 :)
(:*******************************************************:)
namespace-uri(<p:e xmlns:p="http://example.com/{{{{{{}}}}}}asd"/>)
