from itertools import combinations as c

N,M=[int(i) for i in input().split()]
for i in c(range(1,N+1),M):
	print(*i)