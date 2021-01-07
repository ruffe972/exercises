package ruffe972.reactive_calculator;

import java.time.Duration;

public class Response {
    private final int iteration;
    private final int functionNumber;
    private final String result;
    private final Duration computationTime;

    /**
     * Number of calculations of another function (not yet delivered).
     */
    private final int queueLength;

    private Response(int iteration, int functionNumber, String result, Duration computationTime, int queueLength) {
        this.iteration = iteration;
        this.functionNumber = functionNumber;
        this.result = result;
        this.computationTime = computationTime;
        this.queueLength = queueLength;
    }

    @Override
    public String toString() {
        return "i=" + iteration +
                ", f=" + functionNumber +
                ", res=" + result +
                ", t=" + computationTime.toMillis();
//                ", in_queue=" + queueLength;
    }

    Builder mutate() {
        return new Builder()
                .setIteration(iteration)
                .setFunctionNumber(functionNumber)
                .setResult(result)
                .setComputationTime(computationTime)
                .setQueueLength(queueLength);
    }

    int getIteration() {
        return iteration;
    }

    int getFunctionNumber() {
        return functionNumber;
    }

    String getResult() {
        return result;
    }

    Duration getComputationTime() {
        return computationTime;
    }

    int getQueueLength() {
        return queueLength;
    }

    static class Builder {
        private int iteration = -1;
        private int functionNumber = -1;
        private String result = "Undefined";
        private Duration computationTime = Duration.ofSeconds(-1);
        private int queueLength = 0;

        Response build() {
            return new Response(iteration, functionNumber, result, computationTime, queueLength);
        }

        Builder setIteration(int iteration) {
            this.iteration = iteration;
            return this;
        }

        Builder setFunctionNumber(int functionNumber) {
            this.functionNumber = functionNumber;
            return this;
        }

        Builder setResult(String result) {
            this.result = result;
            return this;
        }

        Builder setComputationTime(Duration computationTime) {
            this.computationTime = computationTime;
            return this;
        }

        Builder setQueueLength(int queueLength) {
            this.queueLength = queueLength;
            return this;
        }
    }
}