with open("guide.txt", 'r') as file:
    lines = file.read().split('\n')
    total = 0

    for line in lines:
        if (line == ''):
            continue

        opponent = line.split(' ')[0]
        result = line.split(' ')[1]

        if result == 'Z': # Win
            total += 6
        elif result == 'Y': # Tie
            total += 3
        elif result == 'X': # Loss
            total += 0

        if opponent == "A":
            match result:
                case "Z":
                    total += 2
                case "Y":
                    total += 1
                case "X":
                    total += 3
        elif opponent == "B":
            match result:
                case "Z":
                    total += 3
                case "Y":
                    total += 2
                case "X":
                    total += 1
        elif opponent == "C":
            match result:
                case "Z":
                    total += 1
                case "Y":
                    total += 3
                case "X":
                    total += 2

    print(total)

