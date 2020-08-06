// Represents command-line user interface
object Console {

    private const val ERROR_WRONG_INPUT = "Ошибка: неверный ввод."
    private const val SUCCESS_MESSAGE = "Операция выполнена успешно."
    private const val NO_ACCESS_MESSAGE = "Ошибка: отказано в доступе."

    // Run user sessions indefinitely
    tailrec fun runSessions() {
        println("Список пользователей:")
        println(System.getUserNames().joinToString(separator = "\n"))
        val user = loginAndGetUser()
        runForUser(user)
        runSessions()  // Start new session
    }

    // Get the user to login and greet him.
    // Returns this logged-in user.
    private fun loginAndGetUser(): User {
        val user = getUser("User: ")
        println("Идентификация прошла успешно, добро пожаловать в систему.")
        println("Перечень ваших прав:")

        // Print user permissions for all objects
        System.objects.forEachIndexed { i, systemObject ->
            val userPermissions = systemObject.userPermissions(user)
            println("Объект$i: ${userPermissions.description()}")
        }

        return user
    }

    // Read and execute user commands for [user] until they quit
    private tailrec fun runForUser(user: User) {
        print("Жду ваших указаний > ")
        val command = readLine() ?: ""

        if (command == "quit") {
            println("Работа пользователя ${user.userName} завершена. До свидания.")
        } else {
            val permissionType = PermissionType.fromString(command)

            // Call action handler for valid permission
            when (permissionType) {
                PermissionType.READ -> readOrWriteFile(user, PermissionType.READ)
                PermissionType.WRITE -> readOrWriteFile(user, PermissionType.WRITE)
                PermissionType.GRANT -> grantPermissions(user)
                null -> println(ERROR_WRONG_INPUT)
            }

            runForUser(user)  // Read and execute another command
        }
    }

    // Wait for the user to input another user's name.
    // Custom [prompt] is printed for requesting input.
    // Returns a user with the given name.
    private tailrec fun getUser(prompt: String): User {
        print(prompt)
        val user = System.getUser(readLine() ?: "")

        return if (user == null) {
            println("Ошибка: пользователь не найден.")
            getUser(prompt)  // Ask for input again
        } else {
            user
        }
    }

    // Wait for the user to input permission type name they want to grant.
    // Returns this permission type.
    private tailrec fun getPermission(): PermissionType {
        print("Какое право передаётся? ")
        val permission = PermissionType.fromString(readLine() ?: "")

        return if (permission == null) {
            println(ERROR_WRONG_INPUT)
            getPermission()  // Ask for input again
        } else {
            permission
        }
    }

    // Wait for the [user] to input object number they want to work with.
    // [permission] affects the message shown before input.
    // Returns an object with the given number.
    private tailrec fun getSystemObject(user: User, permission: PermissionType): SystemObject {

        // Print prompt
        when (permission) {
            PermissionType.READ, PermissionType.WRITE -> {
                print("Над каким объектом производится операция? ")
            }
            PermissionType.GRANT -> print("Право на какой объект передается? ")
        }

        // Read object number from keyboard
        val number = try {
            readLine()?.toInt()
        } catch (e: NumberFormatException) {
            println(ERROR_WRONG_INPUT)
            null
        }

        // Get object with the given number
        val systemObject = if (number == null)
            null
        else
            System.objects.getOrNull(number)


        if (number != null && systemObject == null) {
            println("Ошибка: объект не найден")
        }

        // Ask for an object again if needed
        return systemObject ?: getSystemObject(user, permission)
    }

    // Wait for the [subjectUser] to input data needed for granting a permission, then grant it.
    private fun grantPermissions(subjectUser: User) {
        val systemObject = getSystemObject(subjectUser, PermissionType.GRANT)
        var success = false

        if (systemObject.permissionsCanBeGranted(subjectUser)) {
            val permission = getPermission()

            // User can't grant the permission they do not have themselves
            if (systemObject.canBeGranted(permission, subjectUser)) {
                val objectUser = getUser("Какому пользователю передаётся право? ")
                System.grant(permission, systemObject, objectUser)
                success = true
            }
        }

        println(if (success) SUCCESS_MESSAGE else NO_ACCESS_MESSAGE)
    }

    // Wait for the [user] to input object they want to read/write, then let them do it.
    // [permission] can only be READ or WRITE!
    private fun readOrWriteFile(user: User, permission: PermissionType) {
        val systemObject = getSystemObject(user, permission)

        if (systemObject.userPermissions(user).contains(permission)) {
            println(SUCCESS_MESSAGE)
        } else {
            println(NO_ACCESS_MESSAGE)
        }
    }
}