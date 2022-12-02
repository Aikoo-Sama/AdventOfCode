

with open("list.txt", 'r') as file:
    data = file.read().split('\n')

    biggest = 0
    second = 0
    last = 0
    add = 0

    for element in data:
        if (element == ''):
            print("Add ", add)
            if (add >= biggest):
                biggest = add
            if (add >= second and add < biggest):
                second = add
            if (add >= last or last == 0):
                last = add

            add = 0
        else:
            add += int(element)

    print("Biggest: ", biggest)
    print("Second: ", second)
    print("Last: ", last)
