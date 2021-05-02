N,M=map(int,input().split())

# from itertools import permutations as p
# from itertools import combinations as p
# from itertools import combinations_with_replacement as p
from itertools import product as p
target=range(1,N+1)
# target=list(map(int,input().split(' ')))
# target.sort()
for i in p(target,repeat=M):
    print(*i)
