class SeidelStrategy: SolvingStrategy {

    override fun findSolution(input: InputData): OutputData {

        val newApproximationFinder: NewApproximationFinder = { oldApproximation,
                                                               phiFunctions ->
            val newApproximation = oldApproximation.toMutableList()
            for (i in 0 until oldApproximation.size) {
                newApproximation[i] = phiFunctions[i](newApproximation)
            }
            newApproximation
        }

        return IterationsAndSeidelHelper.findSolution(input, newApproximationFinder)
    }
}