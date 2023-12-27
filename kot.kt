fun main() {
    // Variables
    val greeting: String = "Hello, Kotlin!"
    var count: Int = 42

    // Printing to the console
    println(greeting)
    println("Count: $count")

    // Function call
    displayMessage("Welcome to Kotlin!")

    // Conditional statement
    if (count > 0) {
        println("Count is positive.")
    } else if (count < 0) {
        println("Count is negative.")
    } else {
        println("Count is zero.")
    }

    // Looping
    for (i in 1..5) {
        println("Iteration $i")
    }

    // Nullable variable
    var nullableString: String? = null
    println("Nullable String: $nullableString")

    // Safe call operator
    val length: Int? = nullableString?.length
    println("Length: $length")

    // Elvis operator
    val nonNullLength: Int = nullableString?.length ?: -1
    println("Non-null Length: $nonNullLength")
}

// Function definition
fun displayMessage(message: String) {
    println(message)
}
