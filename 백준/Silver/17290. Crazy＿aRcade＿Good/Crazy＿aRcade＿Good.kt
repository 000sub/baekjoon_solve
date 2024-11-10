import java.util.*;
import java.io.*;

val br = BufferedReader(InputStreamReader(System.`in`))
val bw = BufferedWriter(OutputStreamWriter(System.out))
lateinit var arr: Array<CharArray>
lateinit var canLive: Array<BooleanArray>
var N = 0
var M = 0

fun main() {
    val (n, m) = br.readLine().split(" ").map { it.toInt() }
    N = n-1
    M = m-1

    arr = Array(10) { br.readLine().toCharArray() }
    canLive = Array(10) { BooleanArray(10) { true } }

    for (i in 0..9) {
        for (j in 0..9) {
            if (arr[i][j] == 'o') {
                canLive[i][j] = false
                for (k in 1..9) {
                    if (i + k < 10) canLive[i+k][j] = false
                    if (j + k < 10) canLive[i][j+k] = false
                    if (i - k >= 0) canLive[i-k][j] = false
                    if (j - k >= 0) canLive[i][j-k] = false
                }
            }
        }
    }

    var ans = Integer.MAX_VALUE

    for (i in 0..9) {
        for (j in 0..9) {
            if (canLive[i][j]) {
                ans = Math.min(ans, Math.abs(i - N) + Math.abs(j - M))
            }
        }
    }

    bw.write(ans.toString())
    bw.flush()
    bw.close()
}