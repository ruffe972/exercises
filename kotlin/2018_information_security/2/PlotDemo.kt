
import java.io.File
import org.jfree.chart.plot.PlotOrientation
import org.jfree.chart.ChartFactory
import org.jfree.chart.ChartUtils
import org.jfree.data.xy.XYSeriesCollection
import org.jfree.data.xy.XYSeries

fun main(vararg args: String) {
    PlotDemo.runPasswordLengthDemo()
    PlotDemo.runSymbolGroupsDemo()
}

object PlotDemo {
    private val SYMBOL_GROUPS = setOf(SMALL_LETTERS)
    private val PASSWORD_LENGTHS = 5..7
    private const val PASSWORD_LENGTH = 5
    private val SYMBOL_GROUPS_LIST = listOf(
            setOf(SMALL_LETTERS),
            setOf(SMALL_LETTERS, DIGITS),
            setOf(SMALL_LETTERS, BIG_LETTERS),
            setOf(SMALL_LETTERS, BIG_LETTERS, DIGITS)
    )
    private const val SYMBOL_GROUPS_DEMO_ROUNDS = 2
    private const val IMAGE_WIDTH = 1280
    private const val IMAGE_HEIGHT = 720

    fun runSymbolGroupsDemo() {
        val crackTimeSeries = XYSeries("Время подбора пароля длины $PASSWORD_LENGTH")

        for (symbolGroups in SYMBOL_GROUPS_LIST) {
            var timeSum = 0.0
            for (i in 1..SYMBOL_GROUPS_DEMO_ROUNDS) {
                val password = PasswordGenerator(PASSWORD_LENGTH, symbolGroups).generate()
                println("Пароль: $password")
                timeSum += PasswordCracker(password, symbolGroups).crack()
            }
            crackTimeSeries.add(symbolGroups.flatten().size, timeSum / SYMBOL_GROUPS_DEMO_ROUNDS)
        }

        val dataset = XYSeriesCollection()

        dataset.addSeries(crackTimeSeries)

        val chart = ChartFactory.createXYLineChart(
                "Время взлома пароля в зависимости от задействованных групп символов",
                "Количество символов в используемых группах",
                "Время взлома, сек.",
                dataset,
                PlotOrientation.VERTICAL,
                true, true, false)

        val chartImage = File("pw_symbol_groups_chart.jpg")

        ChartUtils.saveChartAsJPEG(chartImage, chart, IMAGE_WIDTH, IMAGE_HEIGHT)
    }

    fun runPasswordLengthDemo() {
        val maxPasswordLength = PASSWORD_LENGTHS.max() ?: 0
        val maxPassword = PasswordGenerator(maxPasswordLength, SYMBOL_GROUPS).generate()
        val crackTimeSeries = XYSeries("Время подбора префиксов пароля $maxPassword")

        for (passwordLength in PASSWORD_LENGTHS) {
            val password = maxPassword.substring(0, passwordLength)
            println("Пароль: $password")
            val time = PasswordCracker(password, SYMBOL_GROUPS).crack()
            crackTimeSeries.add(passwordLength, time)
        }

        val dataset = XYSeriesCollection()
        dataset.addSeries(crackTimeSeries)

        val chart = ChartFactory.createXYLineChart(
                "Время взлома пароля из строчных букв в зависимости от его длины",
                "Длина пароля",
                "Время взлома, сек.",
                dataset,
                PlotOrientation.VERTICAL,
                true, true, false)
        val chartImage = File("pw_length_chart.jpg")
        ChartUtils.saveChartAsJPEG(chartImage, chart, IMAGE_WIDTH, IMAGE_HEIGHT)
    }
}