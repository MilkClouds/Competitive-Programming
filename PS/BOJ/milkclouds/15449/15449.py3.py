a=list(map(int,input().split()))
from itertools import permutations
ret=0
for a,b,c in permutations(a,3):
    a,b,c=sorted([a,b,c])
    if a+b>c:
        ret+=1
print(ret//6)