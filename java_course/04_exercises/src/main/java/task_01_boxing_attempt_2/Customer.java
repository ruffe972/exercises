package task_01_boxing_attempt_2;

import java.util.ArrayList;
import java.util.List;

class Customer {
    private final String name;
    private final List<Double> transactions = new ArrayList<>();

    Customer(String name, double initialTransaction) {
        this.name = name;
        transactions.add(initialTransaction);
    }

    @Override
    public String toString() {
        return String.format("%s %s", name, transactions.toString());
    }

    void performTransaction(double transaction) {
        transactions.add(transaction);
    }

    String getName() {
        return name;
    }
}
