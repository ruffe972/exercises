public class Main {
    public static void main(String[] args) {
        final var account = new BankAccount();
        account.depositFunds(20);
        account.withdrawFunds(20.01);
        account.withdrawFunds(10.5);
        account.withdrawFunds(9.5);
        account.depositFunds(2);
        account.withdrawFunds(2);
        account.depositFunds(-1);
        account.withdrawFunds(-1);
    }
}
