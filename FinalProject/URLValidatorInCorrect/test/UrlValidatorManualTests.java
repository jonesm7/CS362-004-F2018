import junit.framework.TestCase;

public class UrlValidatorManualTests extends TestCase {
    public void testManualTests() {
        UrlValidator validator = new UrlValidator();
        try {
            System.out.println(validator.isValid("www.google.com") + " for www.google.com");
        } catch (Error | Exception e) {
            System.out.println("exception for www.google.com");
        }
        try {
            System.out.println(validator.isValid("http://www.google.com") + " for http://www.google.com");
        } catch (Error | Exception e) {
            System.out.println("exception for http://www.google.com");
        }
        try {
            System.out.println(validator.isValid("http://www.goOgle.com") + " for http://www.goOgle.com");
        } catch (Error | Exception e) {
            System.out.println("exception for http://www.goOgle.com");
        }
        try {
            System.out.println(validator.isValid("HtTp://www.google.com") + " for HtTp://www.google.com");
        } catch (Error | Exception e) {
            System.out.println("exception for HtTp://www.google.com");
        }
        try {
            System.out.println(validator.isValid("http://wwW.google.com") + " for http://wwW.google.com");
        } catch (Error | Exception e) {
            System.out.println("exception for http://wwW.google.com");
        }
        try {
            System.out.println(validator.isValid("http://www.google.cOm") + " for http://www.google.cOm");
        } catch (Error | Exception e) {
            System.out.println("exception for http://www.google.cOm");
        }
        try {
            System.out.println(validator.isValid("http://www.google.com:80") + " for http://www.google.com:80");
        } catch (Error | Exception e) {
            System.out.println("exception for http://www.google.com:80");
        }
        try {
            System.out.println(validator.isValid("http://www.google.com:90") + " for http://www.google.com:90");
        } catch (Error | Exception e) {
            System.out.println("exception for http://www.google.com:90");
        }
        try {
            System.out.println(validator.isValid("http://www.google.com:65535") + " for http://www.google.com:65535");
        } catch (Error | Exception e) {
            System.out.println("exception for http://www.google.com:65535");
        }
        try {
            System.out.println(validator.isValid("http://www.google.com:65536") + " for http://www.google.com:65536");
        } catch (Error | Exception e) {
            System.out.println("exception for http://www.google.com:65536");
        }
        try {
            System.out.println(validator.isValid("http://www.google.com:0") + " for http://www.google.com:0");
        } catch (Error | Exception e) {
            System.out.println("exception for http://www.google.com:0");
        }
        try {
            System.out.println(validator.isValid("http://www.google.com:-1") + " for http://www.google.com:-1");
        } catch (Error | Exception e) {
            System.out.println("exception for http://www.google.com:-1");
        }
        try {
            System.out.println(validator.isValid("http://www.google.com:80a") + " for http://www.google.com:80a");
        } catch (Error | Exception e) {
            System.out.println("exception for http://www.google.com:80a");
        }
        try {
            System.out.println(validator.isValid("http://www.google.com/hello") + " for http://www.google.com/hello");
        } catch (Error | Exception e) {
            System.out.println("exception for http://www.google.com/hello");
        }
        try {
            System.out.println(validator.isValid("http://www.google.com//hello") + " for http://www.google.com//hello");
        } catch (Error | Exception e) {
            System.out.println("exception for http://www.google.com//hello");
        }
        try {
            System.out.println(validator.isValid("http://www.google.com/hello/test1") + " for http://www.google.com/hello/test1");
        } catch (Error | Exception e) {
            System.out.println("exception for http://www.google.com/hello/test1");
        }
        try {
            System.out.println(validator.isValid("http://www.reddit.com/") + " for http://www.reddit.com/");
        } catch (Error | Exception e) {
            System.out.println("exception for http://www.reddit.com/");
        }
        try {
            System.out.println(validator.isValid("http://www.reddit.com/r/test") + " for http://www.reddit.com/r/test");
        } catch (Error | Exception e) {
            System.out.println("exception for http://www.reddit.com/r/test");
        }
        try {
            System.out.println(validator.isValid("http://www.youtube.com") + " for http://www.youtube.com");
        } catch (Error | Exception e) {
            System.out.println("exception for http://www.youtube.com");
        }
        try {
            System.out.println(validator.isValid("http://www.youtube.com/results?search_query=test") + " for http://www.youtube.com/results?search_query=test");
        } catch (Error | Exception e) {
            System.out.println("exception for http://www.youtube.com/results?search_query=test");
        }
        try {
            System.out.println(validator.isValid("http:/www.google.com") + " for http:/www.google.com");
        } catch (Error | Exception e) {
            System.out.println("exception for http:/www.google.com");
        }
        try {
            System.out.println(validator.isValid("http:/www.reddit.com/r") + " for http:/www.reddit.com/r");
        } catch (Error | Exception e) {
            System.out.println("exception for http:/www.reddit.com/r");
        }
        try {
            System.out.println(validator.isValid("http:/www.reddit.com/r/test") + " for http:/www.reddit.com/r/test");
        } catch (Error | Exception e) {
            System.out.println("exception for http:/www.reddit.com/r/test");
        }
        try {
            System.out.println(validator.isValid("http:www.reddit.com") + " for http:www.reddit.com");
        } catch (Error | Exception e) {
            System.out.println("exception for http:www.reddit.com");
        }
        try {
            System.out.println(validator.isValid("http:///www.google.com") + " for http:///www.google.com");
        } catch (Error | Exception e) {
            System.out.println("exception for http:///www.google.com");
        }
        try {
            System.out.println(validator.isValid("http:////www.google.com") + " for http:////www.google.com");
        } catch (Error | Exception e) {
            System.out.println("exception for http:////www.google.com");
        }
        try {
            System.out.println(validator.isValid("http:://www.google.com") + " for http:://www.google.com");
        } catch (Error | Exception e) {
            System.out.println("exception for http:://www.google.com");
        }
        try {
            System.out.println(validator.isValid("http//www.google.com") + " for http//www.google.com");
        } catch (Error | Exception e) {
            System.out.println("exception for http//www.google.com");
        }
        try {
            System.out.println(validator.isValid("htt://www.google.com") + " for htt://www.google.com");
        } catch (Error | Exception e) {
            System.out.println("exception for htt://www.google.com");
        }
        try {
            System.out.println(validator.isValid("h ttp://www.google.com") + " for h ttp://www.google.com");
        } catch (Error | Exception e) {
            System.out.println("exception for h ttp://www.google.com");
        }
        try {
            System.out.println(validator.isValid("http://ww w.google.com") + " for http://ww w.google.com");
        } catch (Error | Exception e) {
            System.out.println("exception for http://ww w.google.com");
        }
        try {
            System.out.println(validator.isValid("http://www.g oogle.com") + " for http://www.g oogle.com");
        } catch (Error | Exception e) {
            System.out.println("exception for http://www.g oogle.com");
        }
        try {
            System.out.println(validator.isValid("http://www.google.c om") + " for http://www.google.c om");
        } catch (Error | Exception e) {
            System.out.println("exception for http://www.google.c om");
        }
        try {
            System.out.println(validator.isValid("http://www.notarealsite.com") + " for http://www.notarealsite.com");
        } catch (Error | Exception e) {
            System.out.println("exception for http://www.notarealsite.com");
        }
        try {
            System.out.println(validator.isValid("http://ww.google.com") + " for http://ww.google.com");
        } catch (Error | Exception e) {
            System.out.println("exception for http://ww.google.com");
        }
        try {
            System.out.println(validator.isValid("http://w.google.com") + " for http://w.google.com");
        } catch (Error | Exception e) {
            System.out.println("exception for http://w.google.com");
        }
        try {
            System.out.println(validator.isValid("http://google.com") + " for http://google.com");
        } catch (Error | Exception e) {
            System.out.println("exception for http://google.com");
        }
        try {
            System.out.println(validator.isValid("http://www.google.con") + " for http://www.google.con");
        } catch (Error | Exception e) {
            System.out.println("exception for http://www.google.con");
        }
        try {
            System.out.println(validator.isValid("http://oregonstate.edu") + " for http://oregonstate.edu");
        } catch (Error | Exception e) {
            System.out.println("exception for http://oregonstate.edu");
        }
        try {
            System.out.println(validator.isValid("http://oregonstate.ed") + " for http://oregonstate.ed");
        } catch (Error | Exception e) {
            System.out.println("exception for http://oregonstate.ed");
        }
        try {
            System.out.println(validator.isValid("http://www.code.org") + " for http://www.code.org");
        } catch (Error | Exception e) {
            System.out.println("exception for http://www.code.org");
        }
        try {
            System.out.println(validator.isValid("http://www.code.or") + " for http://www.code.or");
        } catch (Error | Exception e) {
            System.out.println("exception for http://www.code.or");
        }
        try {
            System.out.println(validator.isValid("http://studentaid.ed.gov") + " for http://studentaid.ed.gov");
        } catch (Error | Exception e) {
            System.out.println("exception for http://studentaid.ed.gov");
        }
        try {
            System.out.println(validator.isValid("http://studentaid.ed.govv") + " for http://studentaid.ed.govv");
        } catch (Error | Exception e) {
            System.out.println("exception for http://studentaid.ed.govv");
        }
    }
}
