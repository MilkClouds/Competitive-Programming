import sys
from heapq import *
input=sys.stdin.readline
n,k=map(int,input().split())


jew=[tuple(map(int,input().split())) for _ in range(n)]
jew.sort()

bags=[int(input())for _ in range(k)]
bags.sort()

ans=0;j=0;heap=[]
for i in range(k):
    while j<n and jew[j][0]<=bags[i]: heappush(heap,-jew[j][1]) or exec('j+=1')
    if heap:
        ans+=-heappop(heap)

print(ans)
