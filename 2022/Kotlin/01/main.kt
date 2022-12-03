import java.io.File


fun main() {
    val file = File("list.txt")
    val lines = file.readLines()

    var sum: Int = 0
    var array: List<Int> = ArrayList<Int>()

    lines.forEach {
        if (it.isNotEmpty()) {
            sum += it.toInt()
        } else {
            array = array.plus(sum)
            sum = 0
        }
    }

    array = array.plus(sum)

    val first = array.maxOrNull()
    var second = 0
    var third = 0

    for (i in 0 until array.size) {
        if (array[i] > second && array[i] < first!!) {
            third = second
            second = array[i]
        } else if (array[i] > third && array[i] < second) {
            third = array[i]
        }
    }

    println("First: $first")
    println("Second: $second")
    println("Third: $third")
    println("Sum: ${first!! + second + third}")
}
