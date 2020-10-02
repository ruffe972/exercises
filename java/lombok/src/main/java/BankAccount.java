import lombok.Getter;
import lombok.Setter;

// Challenge 1, no constructors
@Getter
@Setter
public class BankAccount {
    private static final String NEGATIVE_FUNDS_ERROR_MESSAGE = "Funds should be > 0.";
    private static final String SUCCESS_MESSAGE = "Success.";

    private double balance;

    // Non-null
    private String number = "";

    // Non-null
    private String customerName = "";

    // Non-null
    private String customerEMail = "";

    // Non-null
    private String customerPhoneNumber = "";

    public void depositFunds(double funds) {
        var message = "";
        if (funds <= 0) {
            message = NEGATIVE_FUNDS_ERROR_MESSAGE;
        } else {
            balance += funds;
            message = SUCCESS_MESSAGE;
        }
        System.out.println(message);
    }

    public void withdrawFunds(double funds) {
        var message = "";
        if (funds <= 0) {
            message = NEGATIVE_FUNDS_ERROR_MESSAGE;
        } else if (balance - funds < 0) {
            message = "Not enough money.";
        } else {
            balance -= funds;
            message = SUCCESS_MESSAGE;
        }
        System.out.println(message);
    }
}
