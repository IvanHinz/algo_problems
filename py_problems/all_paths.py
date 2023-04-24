# find all paths with recursion
def find_paths(current_list, index):
    if index < len(heap):
        current_list.append(heap[index])

    if index * 2 + 1 >= len(heap):
        if not (sum(current_list) % divisor):
            satisf_paths.append(current_list)
        return True

    first_way = current_list[:]
    second_way = current_list[:]
    find_paths(first_way, 2 * index + 1)
    find_paths(second_way, 2 * index + 2)


def printPath(given_path):
    ans = ""

    for i in range(len(given_path) - 1):
        ans += str(given_path[i]) + "--->"
    ans += str(given_path[-1])
    return ans


divisor = int(input())
heap = list(map(int, str(input()).split("|")))
satisf_paths = list(list())

find_paths([], 0)

if len(satisf_paths) == 0:
    print(-1)
else:
    for i in range(len(satisf_paths)):
        print(printPath(satisf_paths[i]))
