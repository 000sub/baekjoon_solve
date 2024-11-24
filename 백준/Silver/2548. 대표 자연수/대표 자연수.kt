fun main() {
    val N = readln().toInt()
    val arr = readln().split(" ").map { it.toInt() }
    val sortedArr = arr.sorted()
    if (N % 2 == 0) println(sortedArr[sortedArr.size / 2 - 1])
    else println(sortedArr[sortedArr.size / 2])
}