package ruffe972.reactive_calculator;

import org.graalvm.polyglot.Context;
import org.graalvm.polyglot.Value;
import reactor.core.publisher.Mono;

public class JSRunner {
    private final String code;

    JSRunner(String code) {
        this.code = code;
    }

    /**
     * Can error with PolyglotException
     */
    Mono<Void> validate() {
        var evaluate = Mono.fromRunnable(() -> {
            try (var context = Context.create()) {
                evaluate(context);
            }
        });
        return evaluate.then();
    }

    /**
     * Should be called only after {@link JSRunner#validate()} completes successfully
     */
    Mono<String> run(int arg) {
        return Mono.fromSupplier(() -> {
            try (var context = Context.create()) {
                return evaluate(context).execute(arg).asString();
            }
        });
    }

    private Value evaluate(Context context) {
        return context.eval("js", code);
    }
}