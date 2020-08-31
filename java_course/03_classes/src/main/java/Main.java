public class Main {

    private static void debugBankAccount() {
        final var account = new BankAccount();
        account.setCustomerEMail("test@example.com");
        final String eMail = account.getCustomerEMail();
        account.depositFunds(20);
        account.withdrawFunds(20.01);
        account.withdrawFunds(10.5);
        account.withdrawFunds(9.5);
        account.depositFunds(2);
        account.withdrawFunds(2);
        account.depositFunds(-1);
        account.withdrawFunds(-1);
    }

    private static void debugVipCustomer() {
        final var customer1 = new VipCustomer();
        final double creditLimit = customer1.getCreditLimit();
        final var customer2 = new VipCustomer("Ivan", "me@home.com");
        final var customer3 = new VipCustomer("Vika", "wow@wow.com", 200);
    }

    public static void main(final String[] args) {
    }
}
