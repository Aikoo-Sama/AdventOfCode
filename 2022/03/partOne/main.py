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
            arr.append(letter) if letter in second else None
            second = second.replace(letter, "") if letter in second else second

for letter in arr:
        total += alphabet.index(letter.lower()) + 1 if letter.islower() else alphabet.index(letter.lower()) + 27

print(total)
