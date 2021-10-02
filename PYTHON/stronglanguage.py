t=int(input())
for i in range(0,t):
    n,k=map(int,input().split())
    s=input()[:n]
    c=0 
    d=0
    for j in range(0,n):
        if s[j]=='*':
            c+=1
            if (c>d or c==d):
                d=c
        else:
            c=0
    if d>k or d==k:
        print("yes")
    else:
        print("no")
