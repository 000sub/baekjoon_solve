import java.util.Stack

fun main() {
    val N = readln().toInt()
    val arr = readln().split(" ").map {it.toInt()}
    val stack = Stack<Int>()
    var cur = 1;

    for (i in arr) {
        if (cur == i) {
            cur++

            while (stack.isNotEmpty() && stack.peek() == cur) {
                stack.pop()
                cur++
            }
        }
        else stack.push(i)
    }

    println(if (stack.isEmpty()) "Nice" else "Sad")
}