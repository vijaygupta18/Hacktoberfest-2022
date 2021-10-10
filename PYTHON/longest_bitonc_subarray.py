# Function to find the length of the longest bitonic subarray in a list
def findBitonicSublist(A):
 
    if len(A) == 0:
        return
 
    # `I[i]` store the length of the longest increasing sublist,
    # ending at `A[i]`
    I = [1] * len(A)
 
    for i in range(1, len(A)):
        if A[i - 1] < A[i]:
            I[i] = I[i - 1] + 1
 
    # `D[i]` store the length of the longest decreasing sublist,
    # starting with `A[i]`
    D = [1] * len(A)
 
    for i in reversed(range(len(A) - 1)):
        if A[i] > A[i + 1]:
            D[i] = D[i + 1] + 1
 
    # consider each element as a peak and calculate LBS
    lbs_len = 1
    beg = end = 0
 
    for i in range(len(A)):
        if lbs_len < I[i] + D[i] - 1:
            lbs_len = (I[i] + D[i] - 1)
            beg = i - I[i] + 1
            end = i + D[i] - 1
 
    # print the longest bitonic subarray
    print("The length of the longest bitonic subarray is", lbs_len)
    print("The longest bitonic subarray is", A[beg:end+1])
 
 
if __name__ == '__main__':
 
    A = [3, 5, 8, 4, 5, 9, 10, 8, 5, 3, 4]
    findBitonicSublist(A)
