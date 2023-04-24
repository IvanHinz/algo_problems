order_dict = {"A": 1, "B": 2, "P": 3, "G": 4, "S": 5}
ultimate_dict = {x: [] for x in range(0, 60)}
letter_count = {chr(i + 64): i for i in range(1, 27)}
letter_count[" "] = 0

words_number = int(input())
current_list = list()

for i in range(words_number):
    current_list.append(str(input()))

max_length = len(max(current_list, key=len)) - 6

# sorting for words
for i in range(5 + max_length, 5, -1):
    for elem in current_list:
        if i < len(elem):
            ultimate_dict[letter_count[elem[i]]].append(elem)
        else:
            ultimate_dict[letter_count[" "]].append(elem)
    current_list.clear()
    for j in range(0, 27):
        for q in ultimate_dict[j]:
            current_list.append(q)
    for t in range(0, 27):
        ultimate_dict[t].clear()

# sorting by minutes
for elem in current_list:
    ultimate_dict[int(elem[4:6])].append(elem)

current_list.clear()
for i in range(0, 60):
    for j in ultimate_dict[i]:
        current_list.append(j)

for i in range(0, 60):
    ultimate_dict[i].clear()

# sorting by hour
for elem in current_list:
    ultimate_dict[int(elem[2:4])].append(elem)

current_list.clear()
for i in range(0, 25):
    for j in ultimate_dict[i]:
        current_list.append(j)

for i in range(0, 25):
    ultimate_dict[i].clear()

# sorting by card
for elem in current_list:
    ultimate_dict[order_dict[elem[1]]].append(elem)

current_list.clear()
for i in range(2, 6):
    for j in ultimate_dict[i]:
        current_list.append(j)

for i in range(0, 6):
    ultimate_dict[i].clear()

# sorting by needs
for elem in current_list:
    ultimate_dict[order_dict[elem[0]]].append(elem)

current_list.clear()
for i in range(1, 3):
    for j in ultimate_dict[i]:
        current_list.append(j)

for elem in current_list:
    print(elem)
