package ruffe972.reactive_calculator;

import org.graalvm.polyglot.PolyglotException;
import org.springframework.web.reactive.function.server.ServerRequest;
import reactor.core.publisher.Mono;

import java.util.List;
import java.util.NoSuchElementException;

public class Request {
    private static final int MAX_ITERATIONS = 999_999_999;
    private static final String BAD_ITERATIONS_MESSAGE = String.format(
            "Iterations should be an integer between 1 and %d",
            MAX_ITERATIONS);
    final int iterations;
    final boolean orderedOutput;
    private final List<String> functions;

    /**
     * Can error with BadRequestException
     */
    static Mono<Request> from(ServerRequest serverRequest) {
        try {
            var request = new Request(serverRequest);
            var validateFirst = request.validate(1);
            var validateSecond = request.validate(2);
            return validateFirst.mergeWith(validateSecond)
                    .then(Mono.just(request));
        } catch (BadRequestException e) {
            return Mono.error(e);
        }
    }

    private Mono<Void> validate(int functionNumber) {
        return new JSRunner(getFunction(functionNumber))
                .validate()
                .onErrorMap(PolyglotException.class, e -> {
                    var message = String.format(
                            "Error evaluating function %d.\n%s",
                            functionNumber,
                            e.getMessage());
                    return new BadRequestException(message);
                });
    }

    /**
     * @throws RuntimeException for bad function number.
     */
    String getFunction(int i) {
        return functions.get(i - 1);
    }

    private Request(ServerRequest serverRequest) {
        try {
            iterations = Integer.parseInt(
                    serverRequest.queryParam("iterations").orElseThrow()
            );
            if (iterations <= 0) {
                throw new BadRequestException(BAD_ITERATIONS_MESSAGE);
            }
            orderedOutput = Boolean.parseBoolean(
                    serverRequest.queryParam("ordered").orElseThrow()
            );
            functions = List.of(
                    serverRequest.queryParam("function1").orElseThrow(),
                    serverRequest.queryParam("function2").orElseThrow());
        } catch (NoSuchElementException e) {
            throw new BadRequestException("");
        } catch (NumberFormatException e) {
            throw new BadRequestException(BAD_ITERATIONS_MESSAGE);
        }
    }
}
