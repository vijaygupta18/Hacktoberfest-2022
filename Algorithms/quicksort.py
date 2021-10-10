#QUICK SORT

from sys import stdin, stdout

# This function takes first element as pivot, places the pivot element at its correct position in sorted array,
# and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot


def partition(ar, low, high):

    pivot = ar[low]
    i, j = low, high

    while (i < j):
        # loop runs until we receive element>pivot
        while (i <= high and ar[i] <= pivot):
            i += 1
        # loop runs until we receive element<pivot
        while (j >= 0 and ar[j] > pivot):
            j -= 1

        if(i < j):
            ar[i], ar[j] = ar[j], ar[i]

    ar[low], ar[j] = ar[j], ar[low]
    return(j)


def QuickSort(ar, low, high):
    if(len(ar) == 1):
        return (ar)
    if(low < high):
        j = partition(ar, low, high)
        QuickSort(ar, low, j-1)
        QuickSort(ar, j+1, high)


if __name__ == "__main__":
    ar = list(map(int, stdin.readline().split()))
    low, high = 0, len(ar)-1
    QuickSort(ar, low, high)
    print(*ar)