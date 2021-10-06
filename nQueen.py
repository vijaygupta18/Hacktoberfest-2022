def isSafe(x,y):
    global lst1
    for i in range(x,-1,-1):
        if lst1[i][y]==1:
            return False
    #print("Verticle checked")
    row=x
    col=y
    while row>=0 and col>=0:
        if lst1[row][col]==1:
            return False
        row-=1
        col-=1
    #print("digonl 2 checked")

    row=x
    col=y
    while row>=0 and col<len(lst1):
        if lst1[row][col]==1:
            return False
        row-=1
        col+=1
    #print("digonl 2 checked")

    return True


def nQueen(x):
    global lst1
    #for i in lst1:
        #print(i)
    #print()
    if x>=len(lst1):
        return True
    for col in range(len(lst1)):
        if isSafe(x,col):
            lst1[x][col]=1
            if(nQueen(x+1)):
                return True
            lst1[x][col]=0
    return False


n=int(input())
lst1=[]
for i in range(n):
    lst1.append([0]*n)

if nQueen(0):
    for i in lst1:
        print(i) 

              
