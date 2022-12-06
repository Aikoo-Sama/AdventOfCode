alphabet = "abcdefghijklmnopqrstuvwxyz"

with open("backpack.txt", 'r') as file:
    backpacks = file.read().split("\n")
    total = 0
    arr = []

    for backpack in backpacks:
        if (backpack == ""):
            continue


        first = backpack[:len(backpack) // 2]
        second = backpack[len(backpack) // 2:]

        for letter in first:
            for letter2 in second:
                if (letter == letter2):
                    arr.append(letter)
                    second = second.replace(letter, "")
                    break

for letter in arr:
        total += alphabet.index(letter.lower()) + 1 if letter.islower() else alphabet.index(letter.lower()) + 27

print(total)
