data class SystemParameters(val a: Double, val b: Double, val c: Double)

data class InputData(val strategyName: String,
                     val firstApproximation: List<Double>,
                     val errorMargin: Double,
                     val systemParameters: SystemParameters)

data class OutputData(val solution: List<Double>,
                      val step: Int,
                      val time: Long = 0)