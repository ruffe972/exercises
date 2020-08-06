import java.util.*

val SMALL_LETTERS = ('a'..'z').toSet()
val BIG_LETTERS = ('A'..'Z').toSet()

val DIGITS = ('0'..'9').toSet()

val DEFAULT_SYMBOL_GROUPS = setOf(SMALL_LETTERS, BIG_LETTERS, DIGITS)

fun IntRange.random() = Random().nextInt((endInclusive + 1) - start) + start

fun <T> List<T>.random() = this[this.indices.random()]

fun main(vararg args: String) {
    val password = PasswordGenerator(5, DEFAULT_SYMBOL_GROUPS).generate()
    println("""
        |Пароль: $password
        |Нажмите Enter, чтобы начать подбор пароля.
        |Выйти можно с помощью ^C в терминале ОС (или ^F2 в терминале Intellij Idea).
    """.trimMargin())
    readLine()
    PasswordCracker(password, DEFAULT_SYMBOL_GROUPS).crack()
}