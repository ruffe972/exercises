package e_04_boxing_attempt_2;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

class Bank {
    private final List<Branch> branches = new ArrayList<>();
    private final String name;

    Bank(String name) {
        this.name = name;
    }

    private Optional<Branch> getBranch(String branchName) {
        return branches.stream()
                .filter(branch -> branch.getName().equals(branchName))
                .findAny();
    }

    void addBranch(String branchName) {
        if (getBranch(branchName).isPresent()) {
            System.out.println("Branch with this name already exists.");
        } else {
            branches.add(new Branch(branchName));
        }
    }

    static private void showNoBranchError() {
        System.out.println("No branch with this name.");
    }

    void addCustomer(String branchName, String customerName, double initialTransaction) {
        getBranch(branchName).ifPresentOrElse(
                branch -> branch.addCustomer(customerName, initialTransaction),
                Bank::showNoBranchError);
    }

    void performTransaction(String branchName, String customerName, double transaction) {
        getBranch(branchName).ifPresentOrElse(
                branch -> branch.performTransaction(customerName, transaction),
                Bank::showNoBranchError);
    }

    void listCustomers(String branchName, boolean showTransactions) {
        getBranch(branchName).ifPresentOrElse(
                branch -> branch.listCustomers(showTransactions),
                Bank::showNoBranchError);
    }

    String getName() {
        return name;
    }
}
