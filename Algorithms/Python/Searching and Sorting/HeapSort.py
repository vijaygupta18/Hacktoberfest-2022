# Updated Python program for implementation of heap Sort
def heapify(arr, n, i):
	largest = i 
	l = 2 * i + 1	 # left = 2*i + 1
	r = 2 * i + 2	 # right = 2*i + 2

	if l < n and arr[large] < arr[l]:
		large = l
	if r < n and arr[large] < arr[r]:
		large = r

	# Change root, if needed
	if large != i:
		arr[i], arr[large] = arr[large], arr[i] # swap

		heapify(arr, n, large)


def heapSort(arr):
	n = len(arr)

	# Build a maxheap.
	for i in range(n//2 - 1, -1, -1):
		heapify(arr, n, i)
	for i in range(n-1, 0, -1):
		arr[i], arr[0] = arr[0], arr[i] # swap
		heapify(arr, i, 0)


# Driver code
arr = [12, 11, 13, 5, 6, 7]
heapSort(arr)
n = len(arr)
print("Sorted array is")
for i in range(n):
	print("%d" % arr[i]),
