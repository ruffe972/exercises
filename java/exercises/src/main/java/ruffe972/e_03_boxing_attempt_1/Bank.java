package ruffe972.e_03_boxing_attempt_1;

import java.util.ArrayList;
import java.util.List;

class Bank {
    private final List<Branch> branches = new ArrayList<>();

    void addBranch(Branch branch) {
        branches.add(branch);
    }
}
