import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import kotlin.math.pow


val m: Map<String, Int> = mapOf(
    "black" to 0,
    "brown" to 1,
    "red" to 2,
    "orange" to 3,
    "yellow" to 4,
    "green" to 5,
    "blue" to 6,
    "violet" to 7,
    "grey" to 8,
    "white" to 9,
)

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val first = br.readLine()
    val second = br.readLine()
    val third = br.readLine()

    val result = ((m[first] ?: 0) * 10 + (m[second] ?: 0)) * (10.0.pow(m[third] ?: 0)).toLong()
    bw.write(result.toString())
    bw.flush()
    bw.close()
    br.close()
}