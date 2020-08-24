import java.io.File
import java.io.PrintWriter

object FileIOHandler {

    fun readData(): InputData {
        val inputFileLines = File("txt/input.txt").readLines()
        val (a, b, c) = inputFileLines[1].split(' ').map(String::toDouble)
        return InputData(inputFileLines[2],
                inputFileLines[3].split(' ').map(String::toDouble),
                inputFileLines[0].toDouble(),
                SystemParameters(a, b, c))
    }

    fun writeResult(output: OutputData) {

        val solutionLines = output.solution.mapIndexed { i, s ->
            "x${i + 1} = $s"
        }

        PrintWriter("txt/output.txt").use { out ->
            solutionLines.forEach { out.println(it) }
            out.println("k = ${output.step}")
            out.println("time = ${output.time} ms")
        }
    }
}