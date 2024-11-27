fun main() {
    while (true) {
        val set = mutableSetOf<Int>()
        val input = readLine() ?: break

        for (i in 1..input.toInt()) {
            val str = readln()
            var num = 0
            for (c in str) {
                num = num or (1 shl (c - '0'))
            }
            set.add(num)
        }
        println(set.size)
    }
}