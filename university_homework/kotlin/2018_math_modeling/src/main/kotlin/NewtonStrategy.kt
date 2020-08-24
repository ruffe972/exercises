import koma.end
import koma.mat
import koma.matrix.Matrix
import kotlin.math.*

class NewtonStrategy: SolvingStrategy {

    // @formatter:off
    private fun jacobiMatrix(input: InputData, x: List<Double>): Matrix<Double> {
        val (a, b, c) = input.systemParameters
        return mat[
                2 * a * x[0] - x[1] - b, -x[0] end
                c / x[0] / ln(10.0) + 1, -2 * x[1]
        ]
    }

    private fun equationFunctions(input: InputData, x: List<Double>): Matrix<Double> {
        val (a, b, c) = input.systemParameters
        return mat[
                a * x[0] * x[0] - x[0] * x[1] - b * x[0] + 1,
                x[0] + c * log10(x[0]) - x[1] * x[1]
        ].T()
    }
    // @formatter:on

    override fun findSolution(input: InputData): OutputData {

        tailrec fun findSolution(oldApproximation: List<Double>, step: Int): OutputData {
            val inversedJacobi = jacobiMatrix(input, oldApproximation).inv()
            val appliedEquationFunctions = equationFunctions(input, oldApproximation)
            val vectorDelta = (-inversedJacobi * appliedEquationFunctions).toList()
            val newApproximation = oldApproximation.zip(vectorDelta, Double::plus)
            val scalarDelta = MathHelper.scalarDelta(oldApproximation, newApproximation)
            return if (scalarDelta <= input.errorMargin) {
                OutputData(newApproximation, step)
            } else {
                findSolution(newApproximation, step + 1)
            }
        }

        return findSolution(input.firstApproximation, 0)
    }
}