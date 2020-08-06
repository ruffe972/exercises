import kotlin.math.*

typealias NewApproximationFinder = (List<Double>, List<VectorToScalar>) -> List<Double>

object IterationsAndSeidelHelper {

    private fun findSolution(phiFunctions: List<VectorToScalar>,
                             input: InputData,
                             newApproximationFinder: NewApproximationFinder): OutputData {

        tailrec fun findSolution(oldApproximation: List<Double>, step: Int): OutputData {
            val newApproximation = newApproximationFinder(oldApproximation, phiFunctions)
            val delta = MathHelper.scalarDelta(oldApproximation, newApproximation)
            return if (delta <= input.errorMargin) {
                OutputData(newApproximation, step)
            } else {
                findSolution(newApproximation, step + 1)
            }
        }

        return findSolution(input.firstApproximation, 0)
    }

    fun findSolution(input: InputData,
                     newApproximationFinder: NewApproximationFinder): OutputData {
        val (a, b, c) = input.systemParameters

        val phi0: VectorToScalar = { x ->
            sqrt((x[0] * (x[1] + b) - 1) / a)
        }

        val phi1: VectorToScalar = {x ->
            sqrt(x[0] + c * log10(x[0]))
        }

        return findSolution(listOf(phi0, phi1), input, newApproximationFinder)
    }
}