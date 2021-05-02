N,M=map(int,input().split())

# from itertools import permutations as p
from itertools import combinations as p
# from itertools import combinations_with_replacement as p
# from itertools import product as p
# target=range(1,N+1)
target=list(map(int,input().split(' ')))
target.sort()
already={}
for i in p(target,M):
    if already.get(i): continue
    already.setdefault(i,1)
    print(*i)
