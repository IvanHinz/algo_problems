# definition for a node of linked list
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# print the list
def printNode(given_node):
    ans = ""
    # we add ---> for all nodes except the last
    while given_node.next is not None:
        ans += str(given_node.val) + "--->"
        given_node = given_node.next
    ans += str(given_node.val)
    return ans


# array with our lists
lists = []
lists_num = int(input())

for i in range(lists_num):
    keys = str(input()).split("--->")
    first = ListNode(int(keys[0]))
    # putting all other nodes in a list
    mid_point = first
    for j in range(1, len(keys)):
        new_node = ListNode(int(keys[j]))
        mid_point.next = new_node
        mid_point = new_node
    lists.append(first)

for i in range(1, len(lists)):
    current_node = lists[i]
    while current_node is not None:
        fusion_node = lists[0]
        if current_node.val <= fusion_node.val:
            intermid_pointer = current_node.next
            current_node.next = fusion_node
            lists[0] = current_node
        else:
            while fusion_node is not None:
                if fusion_node.val > current_node.val:
                    break
                fusion_node = fusion_node.next

            binding_node = lists[0]
            while binding_node.next != fusion_node:
                binding_node = binding_node.next

            binding_node.next = current_node
            intermid_pointer = current_node.next
            current_node.next = fusion_node
        current_node = intermid_pointer
print(printNode(lists[0]))
