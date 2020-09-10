import lombok.Getter;

// Challenge 2
@Getter
public class VipCustomer {
    static final double DEFAULT_CREDIT_LIMIT = 100;

    // Non-null
    private final String name;

    // Non-null
    private final String eMail;

    private final double creditLimit;

    public VipCustomer(
            final String name,
            final String eMail,
            final double creditLimit) {
        this.name = name;
        this.eMail = eMail;
        this.creditLimit = creditLimit;
    }

    public VipCustomer() {
        this("", "", DEFAULT_CREDIT_LIMIT);
    }

    public VipCustomer(final String name, final String eMail) {
        this(name, eMail, DEFAULT_CREDIT_LIMIT);
    }
}
