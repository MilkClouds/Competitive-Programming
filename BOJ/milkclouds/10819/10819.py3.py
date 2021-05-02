n=int(input())

a=list(map(int,input().split()))
ans=0
from itertools import *
for i in permutations(a,n):
    ret=0
    l=list(i)
    for i in range(n-1):
        ret+=abs(l[i+1]-l[i])
    ans=max(ret,ans)
print(ans)