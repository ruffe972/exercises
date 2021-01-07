package ruffe972.reactive_calculator;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import reactor.core.publisher.Flux;

import java.time.Duration;

@Configuration
public class Config {
    @Bean
    Flux<Unit> computationTimer(@Value("${computation_period}") int computationPeriod) {
        return Flux.interval(Duration.ofMillis(computationPeriod))
                .map(it -> Unit.INSTANCE)
                .share();
    }
}
