import java.io.File
import java.util.*
import kotlin.concurrent.timer
import kotlin.math.ceil
import kotlin.math.pow

class PasswordCracker(private val passwordToFind: String, symbolGroups: Set<Set<Char>>) {
    private var passwordCounter: Double = 0.0
    private var oldPasswordCounter: Double = 0.0
    private var secondsRunning: Double = 0.0
    private val symbols: List<Char> = symbolGroups.flatten()
    private val timer = initAndStartTimer()

    private fun initAndStartTimer(): Timer {

        val passwordAmount = (1..passwordToFind.length)
                .map { symbols.size.toFloat().pow(it) }
                .sum()
        return timer(initialDelay = STATUS_UPDATE_PERIOD, period = STATUS_UPDATE_PERIOD) {
            secondsRunning += 1
            val currentSpeed = (passwordCounter - oldPasswordCounter) / STATUS_UPDATE_PERIOD * 1000
            val averageSpeed = passwordCounter / secondsRunning
            val remainingTime = (passwordAmount - passwordCounter) / averageSpeed
            println("Скорость подбора: " +
                    "%.3f ".format(currentSpeed / 1000000) +
                    " млн. паролей в секунду. Осталось " +
                    "%.0f ".format(ceil(remainingTime)) +
                    "секунд.")
            oldPasswordCounter = passwordCounter
        }
    }

    private fun comparePasswords(guess: String, realPassword: String): Boolean {
        passwordCounter += 1
        return guess == realPassword
    }

    private fun findPassword(passwordToFind: String): Boolean {
        fun findPassword(prefix: String, length: Int): Boolean {
            return if (prefix.length < length) {
                symbols.any { findPassword(prefix + it, length) }
            } else {
                comparePasswords(prefix, passwordToFind)
            }
        }

        return (1..passwordToFind.length).any {
            println("Начинается подбор паролей из $it символа(ов).")
            findPassword("", it)
        }
    }

    fun crack(): Double {
        println("Начинается подбор по самым популярным паролям.")
        val passwordToFindIsCommon = File("txt/common_passwords.txt").useLines { commonPasswords ->
            commonPasswords.any { comparePasswords(it, passwordToFind) }
        }
        val passwordFound = passwordToFindIsCommon || findPassword(passwordToFind)
        timer.cancel()
        timer.purge()
        println(if (passwordFound) "Пароль найден." else "Пароль не найден.")
        return secondsRunning
    }

    companion object {
        private const val STATUS_UPDATE_PERIOD: Long = 1000
    }
}