#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::string> split(std::string line, char delimiter);


int main() {
    std::ifstream input("guide.txt");
    int total = 0;

    for (std::string line; getline(input, line);) {
        std::vector<std::string> splitLine = split(line, ' ');

        std::string opponentChoose = splitLine[0];
        std::string issue = splitLine[1];

        if (issue == "X") {
            issue = "loose";
            total += 0;
        } else if (issue == "Y") {
            issue = "tie";
            total += 3;
        } else if (issue == "Z") {
            issue = "win";
            total += 6;
        }

        /* Reminds:
        rock = 1
        paper = 2
        scissors = 3
        */

        if (opponentChoose == "A") { // rock
            if (issue == "win") {
                total += 2;
            } else if (issue == "tie") {
                total += 1;
            } else if (issue == "loose") {
                total += 3;
            }
        } else if (opponentChoose == "B") { // paper
            if (issue == "win") {
                total += 3;
            } else if (issue == "tie") {
                total += 2;
            } else if (issue == "loose") {
                total += 1;
            }
        } else if (opponentChoose == "C") { // Scissors
            if (issue == "win") {
                total += 1;
            } else if (issue == "tie") {
                total += 3;
            } else if (issue == "loose") {
                total += 2;
            }
        }
    }

    std::cout << "Total: " << total << std::endl;

    return 0;
}

std::vector<std::string> split(std::string line, char delimiter) {
    std::vector<std::string> splitLine;
    std::string word = "";

    for (char c : line) {
        if (c == delimiter) {
            splitLine.push_back(word);
            word = "";
        } else {
            word += c;
        }
    }

    splitLine.push_back(word);

    return splitLine;
}
