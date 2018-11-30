import junit.framework.TestCase;

public class UrlValidatorInputPartitionTests extends TestCase {
    public void testOverallStringPartition() {
        UrlValidator validator = new UrlValidator();
        assertFalse(validator.isValid(null));
        assertFalse(validator.isValid("No pattern match"));

        // This input uses the base choice for every partition
        assertTrue(validator.isValid("http://www.google.com"));
    }

    public void testOverallSchemePartition() {
        UrlValidator validator = new UrlValidator();
        assertFalse(validator.isValid("//www.google.com"));
        assertFalse(validator.isValid("2://www.google.com"));
    }

    public void testDefaultSchemePartition() {
        UrlValidator validator = new UrlValidator();
        assertTrue(validator.isValid("https://www.google.com"));
        assertTrue(validator.isValid("ftp://www.google.com"));
        assertFalse(validator.isValid("file://www.google.com"));
    }

    public void testCustomSchemePartition() {
        UrlValidator validator = new UrlValidator(new String[]{"file"});
        assertFalse(validator.isValid("http://www.google.com"));
        assertTrue(validator.isValid("file://www.google.com"));
    }

    public void testAllSchemesPartition() {
        UrlValidator validator = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);
        assertTrue(validator.isValid("eyeballs://www.google.com"));
    }

    public void testBaseSchemeAuthorityValidatorPartition() {
        RegexValidator authorityValidator = new RegexValidator("\\d+");
        UrlValidator validator = new UrlValidator(authorityValidator, 0L);
        assertTrue(validator.isValid("http://12"));
        assertFalse(validator.isValid("http://lnostril8"));
    }

    public void testBaseSchemeAuthorityIPv6Partition() {
        UrlValidator validator = new UrlValidator();
        assertFalse(validator.isValid("http://[::aaaaa]"));
        assertTrue(validator.isValid("http://[::1]"));
    }

    public void testBaseSchemeIPV4HostPartition() {
        UrlValidator validator = new UrlValidator();
        assertFalse(validator.isValid("http://1.1.1.700"));
        assertTrue(validator.isValid("http://192.0.0.1"));
    }

    public void testBaseSchemeIPV4PortPartition() {
        UrlValidator validator = new UrlValidator();
        assertTrue(validator.isValid("http://www.google.com:80"));
        assertFalse(validator.isValid("http://www.google.com:-1"));
        assertFalse(validator.isValid("http://www.google.com:800000"));
    }

    public void testBaseSchemeAuthorityExtraPartition() {
        UrlValidator validator = new UrlValidator();
        assertFalse(validator.isValid("http://www.google.com\uD83D\uDE0A"));
        assertTrue(validator.isValid("http://www.google.com "));
    }

    public void testCustomSchemeAuthorityPartition() {
        UrlValidator validator = new UrlValidator(new String[]{"file"});
        assertTrue(validator.isValid("file:///"));
        assertFalse(validator.isValid("file://:/"));
        assertTrue(validator.isValid("file://aaa/"));
    }

    public void testPathPartition() {
        UrlValidator validator = new UrlValidator();
        assertFalse(validator.isValid("http://www.google.com/|"));
        assertFalse(validator.isValid(("http://www.google.com/..")));
        assertFalse(validator.isValid("http://www.google.com/a//"));
        assertTrue(validator.isValid("http://www.google.com/"));
    }

    public void testPathTwoSlashesAllowedPartition() {
        UrlValidator validator = new UrlValidator(UrlValidator.ALLOW_2_SLASHES);
        assertTrue(validator.isValid("http://www.google.com/a//"));
        assertTrue(validator.isValid("http://www.google.com/"));
    }

    public void testQueryPartition() {
        UrlValidator validator = new UrlValidator();
        assertTrue(validator.isValid("http://www.google.com?a=b"));
        assertFalse(validator.isValid("http://www.google.com?a= b"));
    }

    public void testDefaultFragmentPartition() {
        UrlValidator validator = new UrlValidator();
        assertTrue(validator.isValid("http://www.google.com#plop"));
    }

    public void testNoFragmentsPartition() {
        UrlValidator validator = new UrlValidator(UrlValidator.NO_FRAGMENTS);
        assertTrue(validator.isValid("http://www.google.com"));
        assertFalse(validator.isValid("http://www.google.com#plop"));
    }
}
