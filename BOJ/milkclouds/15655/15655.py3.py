N,M=map(int,input().split())

from itertools import combinations as p
# from itertools import combinations_with_replacement as p
target=list(map(int,input().split(' ')))
target.sort()
for i in p(target,M):
    print(*i)
