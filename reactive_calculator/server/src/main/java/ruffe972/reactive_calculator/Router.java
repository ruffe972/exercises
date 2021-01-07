package ruffe972.reactive_calculator;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.reactive.function.server.RouterFunction;
import org.springframework.web.reactive.function.server.RouterFunctions;
import org.springframework.web.reactive.function.server.ServerResponse;
import reactor.core.publisher.Flux;

@Configuration
public class Router {
    @Bean
    RouterFunction<ServerResponse> route(Flux<Unit> computationTimer) {
        // MediaType.APPLICATION_JSON // todo
        return RouterFunctions.route()
                .GET("/calculate", serverRequest ->
                        new RequestHandler(serverRequest, computationTimer).handle())
                .build();
    }
}