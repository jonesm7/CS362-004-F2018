import junit.framework.TestCase;

public class UrlValidatorProgrammingTests extends TestCase {
    public void testIsValid(String[] schemes, String[] authorities,
                            String[] ports, String[] paths,
                            String[] queries, Boolean expectedResult) {

        String testUrl;

        UrlValidator urlVal = new UrlValidator(null, null,
                UrlValidator.ALLOW_ALL_SCHEMES);


        for (int scheme = 0; scheme < schemes.length; scheme++) {
            for (int authority = 0; authority < authorities.length;
                 authority++) {
                for (int port = 0; port < ports.length; port++) {
                    for (int path = 0; path < paths.length; path++) {
                        for (int query = 0; query < queries.length; query++) {
                            testUrl = schemes[scheme] +
                                    authorities[authority] +
                                    ports[port] +
                                    paths[path] +
                                    queries[query];

                            Boolean actualResult = urlVal.isValid(testUrl);
                            assertEquals(testUrl, expectedResult, actualResult);
                        }
                    }
                }
            }
        }
    }

    public void testValidCombos() {
        System.out.println("Testing all valid combinations");
        testIsValid(validSchemes, validAuthorities, validPorts,
                validPaths, validQueries, true);
    }

    public void testInvalidSchemes() {
        System.out.println("Testing invalid schemes");
        testIsValid(invalidSchemes, validAuthorities,
                validPorts, validPaths, validQueries,
                false);

    }

    public void testInvalidAuthorities() {
        System.out.println("Testing invalid authorities");
        testIsValid(validSchemes, invalidAuthorities,
                validPorts,
                validPaths, validQueries, false);

    }

    public void testInvalidPorts() {
        System.out.println("Testing invalid ports");
        testIsValid(validSchemes, validAuthorities,
                invalidPorts,
                validPaths, validQueries, false);
    }

    public void testInvalidPaths() {
        System.out.println("Testing invalid paths");
        testIsValid(validSchemes, validAuthorities, validPorts,
                invalidPaths, validQueries, false);

    }

    static String[] validSchemes = {"http://",
            "https://",
            "ftp://",
            "foo://",
            "test://"};

    static String[] invalidSchemes = {"404://",
            "http:",
            "https//",
            "ftp:/",
            "://"};

    static String[] validAuthorities = {"www.google.com",
            "172.217.0.36",
            "flip3.engr.oregonstate.edu",
            "128.193.36.41",
            "oregonstate.instructure.com"};

    static String[] invalidAuthorities = {".google.com",
            "123.456.789.101",
            "flip3.3ngr.or3gonstat3.3du",
            "111.111.111.111.111",
            "oregonstate.instructure.c"};

    static String[] validPorts = {"",
            ":0",
            ":65535",
            ":80",
            ":12345"};

    static String[] invalidPorts = {":eighty",
            ":99999",
            ":.5",
            ":-100",
            ":port"};

    static String[] validPaths = {"",
            "/foo/bar/",
            "/support/release-notes/android",
            "/FinalProject/URLValidatorInCorrect/test/",
            "/courses/1692917/assignments/7334043"};

    static String[] invalidPaths = {"/..",
            "/../",
            "//",
            "/../this/should/not/work",
            "//file"};

    static String[] validQueries = {"",
            "?key=value",
            "?key1=value1&key2=value2",
            "?q=valid+url+queries",
            "?testing=rad"};

    static String[] invalidQueries = {"?:-a",
            "?key=?",
            "?@=me",
            "?[]",
            "?:?"};

}
