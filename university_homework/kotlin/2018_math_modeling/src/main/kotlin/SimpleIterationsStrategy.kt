class SimpleIterationsStrategy: SolvingStrategy {

    override fun findSolution(input: InputData): OutputData {

        val newApproximationFinder: NewApproximationFinder = { oldApproximation, phiFunctions ->
            phiFunctions.map { it(oldApproximation) }
        }

        return IterationsAndSeidelHelper.findSolution(input, newApproximationFinder)
    }
}