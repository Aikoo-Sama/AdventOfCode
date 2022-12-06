#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

enum Issues {
    X,
    Y,
    Z
};

enum OpponentChoose {
    A,
    B,
    C
};

std::map<std::string, Issues> mapIssue;
std::map<std::string, OpponentChoose> mapOpponentChoose;

std::vector<std::string> split(std::string line, char delimiter);
void initMap();

int main() {
    initMap();

    std::ifstream input("guide.txt");
    int total = 0;

    for (std::string line; getline(input, line);) {
        std::vector<std::string> splitLine = split(line, ' ');

        std::string opponentChoose = splitLine[0];
        std::string issue = splitLine[1];

        switch(mapIssue[issue]) {
            case X:
                total += 0;
                break;
            case Y:
                total += 3;
                break;
            case Z:
                total += 6;
                break;
        }

        switch(mapOpponentChoose[opponentChoose]) {
            case A:
                switch (mapIssue[issue]) {
                    case X:
                        total += 3;
                        break;
                    case Y:
                        total += 1;
                        break;
                    case Z:
                        total += 2;
                        break;
                }
                break;
            case B:
                switch (mapIssue[issue]) {
                    case X:
                        total += 1;
                        break;
                    case Y:
                        total += 2;
                        break;
                    case Z:
                        total += 3;
                        break;
                }
                break;
            case C:
                switch (mapIssue[issue]) {
                    case X:
                        total += 2;
                        break;
                    case Y:
                        total += 3;
                        break;
                    case Z:
                        total += 1;
                        break;
                }
                break;
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

void initMap() {
    mapIssue["X"] = X;
    mapIssue["Y"] = Y;
    mapIssue["Z"] = Z;

    mapOpponentChoose["A"] = A;
    mapOpponentChoose["B"] = B;
    mapOpponentChoose["C"] = C;
}
