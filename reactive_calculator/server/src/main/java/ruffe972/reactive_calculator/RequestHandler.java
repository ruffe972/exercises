package ruffe972.reactive_calculator;

import org.springframework.http.codec.ServerSentEvent;
import org.springframework.web.reactive.function.BodyInserters;
import org.springframework.web.reactive.function.server.ServerRequest;
import org.springframework.web.reactive.function.server.ServerResponse;
import reactor.core.publisher.Flux;
import reactor.core.publisher.Mono;

public class RequestHandler {
    private final ServerRequest serverRequest;
    private final Flux<Unit> computationTimer;

    RequestHandler(ServerRequest serverRequest, Flux<Unit> computationTimer) {
        this.serverRequest = serverRequest;
        this.computationTimer = computationTimer;
    }

    Mono<ServerResponse> handle() {
        return ServerResponse.ok()
                .header("Access-Control-Allow-Origin", "http://localhost:3000")
                .body(BodyInserters.fromServerSentEvents(generateEvents()));
    }

    private Flux<ServerSentEvent<String>> generateEvents() {
        return Request.from(serverRequest)
                .map(request -> new ValidRequestHandler(request, computationTimer))
                .flatMapMany(ValidRequestHandler::handle)
                .onErrorResume(BadRequestException.class, e -> Mono.just(
                        ServerSentEvent.<String>builder()
                                .event("error")
                                .data(e.getMessage())
                                .build()));
    }
}