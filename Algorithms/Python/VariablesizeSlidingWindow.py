'''
Find maximum length sub array with sum k
'''

k=int(input())
ar=list(map(int,input().split()))

i=0
j=0
maxlen=0
cursum=0

while(j<len(ar)):
    cursum+=ar[j]

    if( cursum<k ):
        j+=1

    elif( cursum == k ):

        maxlen = max((j-i+1),maxlen)
        j+=1
    
    else:
        while(cursum>k):
            cursum-=ar[i]
            i+=1
        j+=1

print(maxlen)
