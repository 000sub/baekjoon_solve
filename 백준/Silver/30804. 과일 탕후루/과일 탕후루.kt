import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))

fun main() {
    val N = br.readLine().toInt()
    val cnt = IntArray(10)
    val arr = br.readLine().split(" ").map { it.toInt() }
    var ans = 0
    var typeCnt = 0
    val q = ArrayDeque<Int>()

    for (i in arr) {
        q.add(i)
        if (++cnt[i] == 1) typeCnt++

        while (typeCnt > 2) {
            val top = q.removeFirst()
            if (--cnt[top] == 0) typeCnt--
        }

        ans = maxOf(ans, q.size)
    }

    bw.write(ans.toString())
    bw.flush()
    bw.close()
}