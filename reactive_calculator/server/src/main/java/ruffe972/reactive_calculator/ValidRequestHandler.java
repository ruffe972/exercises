package ruffe972.reactive_calculator;

import org.reactivestreams.Publisher;
import org.springframework.http.codec.ServerSentEvent;
import reactor.core.publisher.Flux;
import reactor.core.publisher.Mono;

public class ValidRequestHandler {
    private final Request request;
    private final Flux<Unit> computationTimer;

    ValidRequestHandler(Request request, Flux<Unit> computationTimer) {
        this.request = request;
        this.computationTimer = computationTimer;
    }

    Publisher<ServerSentEvent<String>> handle() {
        return calculateAllIterations(1)
                .mergeWith(calculateAllIterations(2))
                .map(Response::toString)
                .onErrorResume(e -> Mono.just(e.getMessage()))//todo null message
                .map(data -> ServerSentEvent.<String>builder()
                        .data(data)
                        .build())
                .concatWithValues(ServerSentEvent.<String>builder()
                        .event("done")
                        .data("")
                        .build());
    }

    private Flux<Response> calculateAllIterations(int functionNumber) {
        return Flux.range(1, request.iterations)
                .zipWith(this.computationTimer, (iteration, tick) -> iteration)
                .concatMap(iteration -> calculate(functionNumber, iteration));
    }

    private Mono<Response> calculate(int functionNumber, int iteration) {
        return new JSRunner(request.getFunction(functionNumber))
                .run(iteration)
                .timed()
                .map(it -> new Response.Builder()
                        .setFunctionNumber(functionNumber)
                        .setIteration(iteration)
                        .setResult(it.get())
                        .setComputationTime(it.elapsedSinceSubscription())
                        .build());
    }
}
