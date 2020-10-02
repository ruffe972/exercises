package ruffe972.e_04_boxing_attempt_2;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

class Branch {
    private final List<Customer> customers = new ArrayList<>();
    private final String name;

    Branch(String name) {
        this.name = name;
    }

    String getName() {
        return name;
    }

    Optional<Customer> getCustomer(String customerName) {
        return customers.stream()
                .filter(customer -> customer.getName().equals(customerName))
                .findAny();
    }

    void addCustomer(String customerName, double initialTransaction) {
        if (getCustomer(customerName).isPresent()) {
            System.out.println("Customer with this name already exists.");
        } else {
            customers.add(new Customer(customerName, initialTransaction));
        }
    }

    void listCustomers(boolean showTransactions) {
        String output = customers.stream()
                .map(showTransactions ? Customer::toString : Customer::getName)
                .collect(Collectors.joining("\n"));
        System.out.println(output);
    }

    void performTransaction(String customerName, double transaction) {
        getCustomer(customerName).ifPresentOrElse(
                customer -> customer.performTransaction(transaction),
                () -> System.out.println("Customer not found."));
    }
}
