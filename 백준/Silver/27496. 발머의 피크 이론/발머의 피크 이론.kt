fun main() {
    val (N, L) = readln().split(" ").map { it.toInt() }
    val arr = readln().split(" ").map { it.toInt() }
    val sum = IntArray(N + 1)
    var ans = 0

    for (i in 1..N) {
        sum[i] = sum[i - 1] + arr[i - 1]
    }

    for (i in 1..N) {
        val cur = if (i >= L) sum[i] - sum[i - L] else sum[i]
        if (cur in 129..138) ans++
    }
    println(ans)
}