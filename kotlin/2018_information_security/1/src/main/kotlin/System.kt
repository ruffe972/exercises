import kotlin.random.Random

// Type used for user identifiers
typealias UserId = Int

// User of the system. It's helpful to have an [id] so the [userName] can be safely changed.
// [userName is used to login, it's not a full name of the person.
class User(val id: UserId, val userName: String)

// Main program model, stores objects and users.
object System {

    // List of system objects
    val objects: List<SystemObject>

    // Number of objects in the system
    private const val OBJECTS_COUNT = 3

    // User with this id will become an admin after System initialization
    private const val ADMIN_USER_ID = 0

    // Stores the users so they can be easily found by their id
    private val users: Map<UserId, User>

    // Login names used for initializing property "users"
    private val USER_NAMES = listOf(
            "ivan",
            "alex",
            "roman",
            "andrew"
    )

    // Create users and objects
    init {

        // Create users and give them ids in order
        users = USER_NAMES.mapIndexed { i, name ->
            i to User(i, name)
        }.toMap()

        objects = (1..OBJECTS_COUNT).map { objectWithRandomPermissions() }

        // Make single user an admin
        val adminPermissionSet = PermissionType.values().toSet()
        users[ADMIN_USER_ID]?.let { admin ->
            for (systemObject in objects) {
                systemObject.userPermissions(admin).grant(adminPermissionSet)
            }
        }
    }

    // Run command-based UI after system init
    @JvmStatic
    fun main(vararg args: String) {
        Console.runSessions()
    }

    // Get user by [userName].
    // Returns null if they're not found.
    fun getUser(userName: String): User? {
        val usersWithGivenName = users.filterValues { it.userName == userName }
        return usersWithGivenName.values.firstOrNull()
    }

    // List of all users' names
    fun getUserNames(): List<String> {
        return users.values.map { it.userName }
    }

    // Forced permission granting without authority checks.
    // Given [permission] for [systemObject] is granted to [objectUser].
    fun grant(permission: PermissionType,
              systemObject: SystemObject,
              objectUser: User
    ) {
        systemObject.userPermissions(objectUser).grant(permission)
    }

    // Used to init random UserPermissions for all objects
    private fun UserPermissions.Companion.random(): UserPermissions {
        val permissionList = PermissionType.values().filter {
            Random.nextBoolean()
        }
        return UserPermissions(permissionList.toSet())
    }

    // Returns new object with all users being given random permissions
    private fun objectWithRandomPermissions(): SystemObject {
        val objectPermissions: ObjectPermissions = mutableMapOf()
        for (userId in users.keys) {
            objectPermissions[userId] = UserPermissions.random()
        }
        return SystemObject(objectPermissions)
    }
}