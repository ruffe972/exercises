package task_01_boxing_attempt_1;

import java.util.ArrayList;
import java.util.List;

class Customer {
    private final String name;
    private final List<Double> transactions = new ArrayList<>();

    Customer(String name, double initialTransaction) {
        this.name = name;
        transactions.add(initialTransaction);
    }

    String getName() {
        return name;
    }

    void performTransaction(double transaction) {
        transactions.add(transaction);
    }

    void listTransactions() {
        System.out.println(transactions);
    }
}
