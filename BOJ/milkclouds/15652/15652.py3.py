N,M=map(int,input().split())

from itertools import combinations_with_replacement as p
for i in p(range(1,N+1),M):
    print(*i)
