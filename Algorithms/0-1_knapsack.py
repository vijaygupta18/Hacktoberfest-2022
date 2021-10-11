def knapSack(W, wt, val, n):

    if n == 0 or W == 0:
        return 0
    
    if t[n][W] !=-1:
        return t[n][W]
   
    if (wt[n-1] > W):
        t[n][W] = knapSack(W, wt, val, n-1)
        return t[n][W]
    else:
        t[n][W] = max(val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),knapSack(W, wt, val, n-1))
        return t[n][W]
    return t[n][W]
 
 

val = [60, 100, 120]
wt = [10, 20, 30]
W = 50
n = len(val)
t=[[-1 for i in range(100)]for j in range(100)]
print (knapSack(W, wt, val, n))
