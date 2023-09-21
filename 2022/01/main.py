with open("list.txt", 'r') as file:
    data = file.read().split('\n')

    sumOfAllElves = []
    add = 0

    for element in data:
        if (element == ''):
            sumOfAllElves.append(add)
            add = 0
        else:
            add += int(element)

    biggest = max(sumOfAllElves)
    second = 0
    last = 0

    for element in sumOfAllElves:
        if (element > second and element < biggest):
            second = element
        if (element > last and element < second):
            last = element

    print("Biggest: ", biggest)
    print("Second: ", second)
    print("Last: ", last)
    print(biggest + second + last)
