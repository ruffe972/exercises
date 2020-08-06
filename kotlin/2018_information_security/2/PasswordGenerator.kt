import java.io.File

class PasswordGenerator(private val passwordLength: Int,
                        private val symbolGroups: Set<Set<Char>>) {
    private val symbols = symbolGroups.flatten()

    init {
        assert(passwordLength <= MAX_PASSWORD_LENGTH)
    }

    tailrec fun generate(): String {
        val password = List(passwordLength) { symbols.random() }.joinToString("")
        return if (passwordIsGood(password)) {
            password
        } else {
            generate()
        }
    }

    private fun passwordIsGood(password: String): Boolean {
        val allGroupsAreUsed = symbolGroups.all { groupIsUsed(it, password) }
        val passwordIsNotRealWord = !prohibitedPasswords.contains(password.toLowerCase())
        return allGroupsAreUsed && passwordIsNotRealWord
    }

    private fun groupIsUsed(group: Set<Char>, password: String) =
            password.any { group.contains(it) }

    companion object {
        const val MAX_PASSWORD_LENGTH = 7
        private val prohibitedPasswords = File("txt/filtered_words.txt").readLines().toHashSet()
    }
}