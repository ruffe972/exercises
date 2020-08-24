// A user can do something with an object only with the required permissions.
// Single permission can be one of the several types.
// See UserPermissions for the combination of several primitive permissions.
enum class PermissionType {

    // READ: A user can read a file (unexpected!).
    // WRITE: A user can write to a file (who knew!).
    // GRANT: A user can grant his permissions to another user of his choice.
    READ, WRITE, GRANT;

    // Permission type name in natural language.
    fun description() = when(this) {
        READ -> "Чтение"
        WRITE -> "Запись"
        GRANT -> "Передача прав"
    }

    companion object {

        // Number of different permissions
        val AMOUNT = PermissionType.values().size

        // Converts command string to PermissionType.
        // Returns null if the conversion is not successful.
        fun fromString(string: String): PermissionType? {
            return when (string) {
                "read" -> READ
                "write" -> WRITE
                "grant" -> GRANT
                else -> null
            }
        }
    }
}