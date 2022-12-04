alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']

with open("backpack.txt", 'r') as file:
    backpacks = file.read().split("\n")
    letters = {}
    total = 0

    for backpack in backpacks:
        if (backpack == ""):
            continue
        backpack = list(backpack)
        first = backpack[:len(backpack) // 2]
        second = backpack[len(backpack) // 2:]

        for letter in first:
            if letter in second:
                if letter in letters:
                    letters[letter] += 1
                else:
                    letters[letter] = 1


for letter in letters:
    total += alphabet.index(letter) + 1

print(total)
