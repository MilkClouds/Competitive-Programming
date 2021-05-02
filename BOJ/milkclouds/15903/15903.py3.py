n,m=map(int,input().split())
from heapq import *
heap=sorted(list(map(int,input().split())))
for i in range(m):
	h=heappop(heap)+heappop(heap)
	[heappush(heap,h) for i in range(2)]
print(sum(heap))