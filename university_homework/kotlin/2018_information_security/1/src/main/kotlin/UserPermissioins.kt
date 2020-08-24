// Represents set of actions that a user can do with a file.
// See PermissionType for available actions
class UserPermissions(

        // Set of permitted actions
        private var granted: Set<PermissionType> = setOf()
) {
    // Check if this contains a given [permission]
    fun contains(permission: PermissionType) = granted.contains(permission)

    // Returns description of all granted permissions.
    fun description(): String {
        return when {
            granted.isEmpty() -> "Запрет"
            granted.size == PermissionType.AMOUNT -> "Полный доступ"
            else -> granted.toSortedSet().joinToString { it.description() }
        }
    }

    // Compliment the existing permissions with [newPermissions]
    fun grant(newPermissions: Set<PermissionType>) {
        granted += newPermissions
    }

    // Compliment the existing permissions with [permission]
    fun grant(permission: PermissionType) = grant(setOf(permission))

    companion object
}