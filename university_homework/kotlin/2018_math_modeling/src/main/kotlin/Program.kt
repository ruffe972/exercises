import kotlin.system.measureTimeMillis

object Program {

    @JvmStatic
    fun main(vararg args: String) {
        printInfoToConsole()
        val inputData = FileIOHandler.readData()
        val solvingStrategy = chooseStrategy(inputData)
        var outputData = OutputData(listOf(), 0)
        val time = measureTimeMillis {
            outputData = solvingStrategy.findSolution(inputData)
        }
        FileIOHandler.writeResult(outputData.copy(time = time))
    }

    private fun chooseStrategy(inputData: InputData): SolvingStrategy {
        return when (inputData.strategyName) {
            "seidel" -> SeidelStrategy()
            "newton" -> NewtonStrategy()
            else -> SimpleIterationsStrategy()
        }
    }

    private fun printInfoToConsole() {
        val text = """
            |Результат вычислений записан в output.txt.
            |------------------------------------------------------
            |Справка по использованию программы.
            |Формат входного файла input.txt:
            |
            |e
            |a b c
            |strategy_name
            |x y
            |
            |, где е - погрешность;
            |
            |a, b, c - параметры системы
            |a*x1^2 - x1*x2 - b*x1 + 1 = 0
            |x1 + c*lg(x1) - x2^2 = 0
            |
            |strategy_name - это код применяемого мат. метода.
            |Возможные варианты: simple_iterations, seidel, newton.
            |
            |x y - это координаты начального приближения.
            """.trimMargin()
        print(text)
    }
}