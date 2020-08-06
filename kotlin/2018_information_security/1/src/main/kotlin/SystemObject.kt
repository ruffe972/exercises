// Alias for SystemObject().permissions type
typealias ObjectPermissions = MutableMap<UserId, UserPermissions>

// System object (ex. file, cd drive, etc.). Stores permissions for its usage for all users.
class SystemObject(

        // Associated userId with user's permissions for this object
        private val permissions: ObjectPermissions
) {
    // Returns permissions for the [user].
    // If the user object is not registered in the System, returns zero UserPermissions.
    fun userPermissions(user: User): UserPermissions {
        return permissions.getOrDefault(user.id, UserPermissions())
    }

    // Checks if a [user] can grant permissions for this object
    fun permissionsCanBeGranted(user: User): Boolean {
        return userPermissions(user).contains(PermissionType.GRANT)
    }

    // Checks if a [user] can grant [permission] for this object
    fun canBeGranted(permission: PermissionType, user: User): Boolean {
        return permissionsCanBeGranted(user) &&
                userPermissions(user).contains(permission)
    }
}