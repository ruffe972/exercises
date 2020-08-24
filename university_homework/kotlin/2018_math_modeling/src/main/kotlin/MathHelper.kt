import kotlin.math.abs

typealias VectorToScalar = (List<Double>) -> Double

object MathHelper {

    fun scalarDelta(vectorA: List<Double>, vectorB: List<Double>): Double {
        val coordDeltas = vectorA.zip(vectorB) { a, b -> abs(a - b) }
        return coordDeltas.max() ?: 0.0
    }
}
