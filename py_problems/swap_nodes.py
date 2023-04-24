# definition for a node of linked list
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# function for printing the answer
def printNodes(given_node):
    ans = ""
    # we add ---> for all nodes except the last
    while given_node.next is not None:
        ans += str(given_node.val) + "--->"
        given_node = given_node.next
    ans += str(given_node.val)
    return ans


keys = str(input()).split("--->")
first = ListNode(int(keys[0]))

# check if val of first node is zero
number_of_zeros = 0 + (keys[0] == "0")

mid_point = first

# creating nodes
for i in range(1, len(keys)):
    new_node = ListNode(int(keys[i]))
    number_of_zeros += (keys[i] == "0")
    mid_point.next = new_node
    mid_point = new_node

current_node = first
while current_node is not None:
    operating_node = current_node
    if operating_node.val == 0:
        mig_node = operating_node.next
        while mig_node is not None:
            if mig_node.val != 0:
                # swapping values for nodes with zero val and for node with non-zero val
                mig_node.val, operating_node.val = operating_node.val, mig_node.val
                operating_node = mig_node
            mig_node = mig_node.next
    current_node = current_node.next

print(printNodes(first))
