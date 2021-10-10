# Python program to merge two sorted linked lists in-place by Deepanshu Mittal.

# Linked List node
class Node:
	def __init__(self, data):
		self.data = data
		self.next = None

# Function to create newNode in a linkedlist
def newNode(key):

	new_node = Node(0)
	new_node.data = key
	new_node.next = None
	return new_node

# Function to print linked list
def printList(node):

	while (node != None) :
		print( node.data, end =" ")
		node = node.next
	
# Merges two lists with headers as h1 and h2.
def merge(h1, h2):

	if (h1.data > h2.data):
		return merge(h2, h1)
    
    # if only one node in first list simply point its head to second list
	if (h1.next == None) :
		h1.next = h2
		return h1
	
	# Initialize current and next pointers of both lists
	curr1 = h1
	next1 = h1.next
	curr2 = h2
	next2 = h2.next

	while (next1 != None and curr2 != None):
	
		# if curr2 lies in between curr1 and next1
		# then do curr1.curr2.next1
		if ((curr2.data) >= (curr1.data) and
			(curr2.data) <= (next1.data)) :
			next2 = curr2.next
			curr1.next = curr2
			curr2.next = next1

			# now let curr1 and curr2 to point
			# to their immediate next pointers
			curr1 = curr2
			curr2 = next2
		
		else :
			# if more nodes in first list
			if (next1.next) :
				next1 = next1.next
				curr1 = curr1.next
			
			# else point the last node of first list
			# to the remaining nodes of second list
			else :
				next1.next = curr2
				return h1

	return h1

# First Linked List: 10 -> 30 -> 50 
head1 = newNode(10)
head1.next = newNode(30)
head1.next.next = newNode(50)

# Second Linked List: 0 -> 20 -> 40 
head2 = newNode(0)
head2.next = newNode(20)
head2.next.next = newNode(40)

if (head1 == None):
	printList(head2)
if (head2 == None):
	printList(head1)
else:
    mergedhead = merge(head1, head2)
    printList(mergedhead)

# This code is contributed by Deepanshu Mittal @Deepanshu-iiits-it
