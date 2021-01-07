package ruffe972.reactive_calculator;

public class BadRequestException extends RuntimeException {
    BadRequestException(String message) {
        super(message);
    }

    /**
     * @return non-null message.
     */
    @Override
    public String getMessage() {
        return super.getMessage();
    }
}