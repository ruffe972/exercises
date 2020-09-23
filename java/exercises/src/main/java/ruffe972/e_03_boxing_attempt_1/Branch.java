package ruffe972.e_03_boxing_attempt_1;

import java.util.ArrayList;
import java.util.List;

class Branch {
    private final List<Customer> customers = new ArrayList<>();

    void addCustomer(Customer customer) {
        customers.add(customer);
    }

    void listCustomers() {
        for (final var customer : customers) {
            System.out.println(customer.getName());
        }
    }
}
