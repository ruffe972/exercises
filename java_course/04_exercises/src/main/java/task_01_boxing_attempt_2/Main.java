package task_01_boxing_attempt_2;

class Main {
    public static void main(String[] args) {
        var bank = new Bank("VTB");
        bank.addBranch("Murmansk");
        bank.addCustomer("Murmansk", "Ivan", 34.4);
        bank.addCustomer("Murmansk", "Vika", 2);
        bank.addCustomer("Murmansk", "Valya", -0.2);

        bank.addBranch("Saint-Petersburg");
        bank.addCustomer("Saint-Petersburg", "Vova", 1000);

        bank.performTransaction("Murmansk", "Ivan", 23);
        bank.performTransaction("Murmansk", "Ivan", 2);
        bank.performTransaction("Murmansk", "Vika", 0.3);

        bank.listCustomers("Murmansk", true);
        bank.listCustomers("Saint-Petersburg", true);

        bank.addBranch("Moscow");
        bank.addCustomer("Moscow", "Oleg", 5.66);
        bank.addBranch("Murmansk");
        bank.performTransaction("Moscow", "Qwerty", 0);
        bank.addCustomer("Murmansk", "Ivan", 3);
        bank.listCustomers("Moscow", false);
    }
}
