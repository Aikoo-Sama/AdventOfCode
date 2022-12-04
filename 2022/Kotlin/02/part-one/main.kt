import java.io.File

val rock: String = "A"
val paper: String = "B"
val scissors: String = "C"

fun main() {
    val guide = File("guide.txt")
    val guideLines = guide.readLines()
    var total = 0

    guideLines.forEach {
        if (it == "") return

        val opponentChoose = it.split(" ")[0]
        var playerChoose = it.split(" ")[1]
        var points = 0

        when {
            playerChoose == "X" -> {
                playerChoose = "A"
                points += 1
            }
            playerChoose == "Y" -> {
                playerChoose = "B"
                points += 2
            }
            playerChoose == "Z" -> {
                playerChoose = "C"
                points += 3
            }
            else -> {
                points += 0
            }
        }

        val result = getWinner(opponentChoose, playerChoose)

        when (result) {
            0 -> points += 3
            1 -> points += 6
            else -> points += 0
        }

        total += points
    }

    println("Total points: $total")
}

fun getWinner(opponentChoose: String, playerChoose: String): Int {
    return when {
        opponentChoose == playerChoose -> 0
        opponentChoose == rock && playerChoose == paper -> 1
        opponentChoose == rock && playerChoose == scissors -> 2
        opponentChoose == paper && playerChoose == rock -> 2
        opponentChoose == paper && playerChoose == scissors -> 1
        opponentChoose == scissors && playerChoose == rock -> 1
        opponentChoose == scissors && playerChoose == paper -> 2
        else -> 0
    }
}
