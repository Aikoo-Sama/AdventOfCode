import java.io.File

val rock: String = "A"
val paper: String = "B"
val scissors: String = "C"

val win: String = "Z"
val tie: String = "Y"
val loose: String = "X"

fun main() {
    val guide = File("guide.txt")
    val guideLines = guide.readLines()
    var total = 0

    guideLines.forEach {
        if (it == "") return

        val opponentChoose = it.split(" ")[0]
        var issue = it.split(" ")[1]
        var points = 0

        when {
            issue == "X" -> {
                issue = loose
                points += 0
            }
            issue == "Y" -> {
                issue = tie
                points += 3
            }
            issue == "Z" -> {
                issue = win
                points += 6
            }
        }

        val moove = getChooseTo(opponentChoose, issue)

        when (moove) {
            rock -> points += 1
            paper -> points += 2
            scissors -> points += 3
        }

        total += points
    }

    println("Total points: $total")
}

fun getChooseTo(opponentChoose: String, result: String): String {
    return when (opponentChoose) {
        rock -> {
            when (result) {
                win -> paper
                tie -> rock
                loose -> scissors
                else -> ""
            }
        }
        paper -> {
            when (result) {
                win -> scissors
                tie -> paper
                loose -> rock
                else -> ""
            }
        }
        scissors -> {
            when (result) {
                win -> rock
                tie -> scissors
                loose -> paper
                else -> ""
            }
        }
        else -> ""
    }
}
