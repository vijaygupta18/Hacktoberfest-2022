'''
Find maximum sum of sub array with length k
'''

ar = list(map(int,input().split()))
k = int(input())

i=0
j=0
sum=0
maxsum=0
while(j<len(ar)):
    if(j-i+1<k):
        sum+=ar[j]
        j+=1
    elif(j-i+1 == k and i==0):
        sum+=ar[j]
        j+=1
        maxsum = max(sum,maxsum)
    else:
        sum+=ar[j]
        sum-=ar[i]
        i+=1
        j+=1
        maxsum = max(sum,maxsum)
    print(sum)
    print(maxsum)
    print(" ")

print(maxsum)

