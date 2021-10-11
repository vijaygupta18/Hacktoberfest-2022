def mincurr(n):
    d =  [1, 2, 5, 10, 20, 50, 100, 500, 1000]
    l = 8
    curr =[]
    while(l>=0):
        while(n>=d[l]):
            n -=d[l]
            curr.append(d[l])
            
        l -=1
    
    for i in range(0,len(curr)):
        print(curr[i],end=" ")

n=int(input())
mincurr(n)
        
