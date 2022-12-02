

with open("list.txt", 'r') as file:
    data = file.read().split('\n')
    data.pop()

    biggest = 0
    second = 0
    last = 0
    add = 0

    for element in data:
        if (element == ''):
            if (add >= biggest):
                biggest = add
            elif (add >= second):
                second = add
            elif (add >= last):
                last = add
        else:
            add += int(element)

    print(biggest)
