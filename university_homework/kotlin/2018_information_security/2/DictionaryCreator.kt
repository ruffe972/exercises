import java.io.File

fun main(vararg args: String) {
    val filteredWordsPrintWriter = File("txt/filtered_words.txt").printWriter()
    File("txt/english_words.txt").useLines { line ->
        line.filter { it.length <= PasswordGenerator.MAX_PASSWORD_LENGTH }
                .map { it.toLowerCase() }
                .forEach { filteredWordsPrintWriter.println(it) }
    }
}
