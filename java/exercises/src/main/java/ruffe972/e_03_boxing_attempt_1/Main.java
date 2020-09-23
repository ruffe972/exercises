package ruffe972.e_03_boxing_attempt_1;

class Main {
    public static void main(String[] args) {
        final var bank = new Bank();
        final var murmanskBranch = new Branch();
        bank.addBranch(murmanskBranch);

        final var me = new Customer("Ivan Yershov", 0);
        me.performTransaction(-4.3);
        murmanskBranch.addCustomer(me);

        final var vika = new Customer("Vika Vorobyova", 5);
        vika.performTransaction(6);
        murmanskBranch.addCustomer(vika);

        murmanskBranch.listCustomers();
        me.listTransactions();
        vika.listTransactions();
    }
}
