import lombok.Getter;
import lombok.NonNull;
import lombok.Setter;

public class BankAccount {
    private static final String NEGATIVE_FUNDS_ERROR = "Funds should be > 0.";
    private static final String SUCCESS_MESSAGE = "Success.";

    @Getter
    @Setter
    int number;

    @Getter
    @Setter
    double balance;

    @Getter
    @Setter
    @NonNull String name = "";

    @Getter
    @Setter
    @NonNull String eMail = "";

    @Getter
    @Setter
    @NonNull String phoneNumber = "";

    public void depositFunds(double funds) {
        var message = "";
        if (funds <= 0) {
            message = NEGATIVE_FUNDS_ERROR;
        } else {
            balance += funds;
            message = SUCCESS_MESSAGE;
        }
        System.out.println(message);
    }

    public void withdrawFunds(double funds) {
        var message = "";
        if (funds <= 0) {
            message = NEGATIVE_FUNDS_ERROR;
        } else if (balance - funds < 0) {
            message = "Not enough money.";
        } else {
            balance -= funds;
            message = SUCCESS_MESSAGE;
        }
        System.out.println(message);
    }
}
