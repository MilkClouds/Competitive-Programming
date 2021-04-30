import sys
input=sys.stdin.readline
from heapq import *
from collections import deque
rr=[]
def print(t):
	sys.stdout.write(str(t)+'\n')
for _ in range(int(input())):
	t=int(input())
	if t==0:
		print(-heappop(rr) if rr else 0)
	else:
		heappush(rr,-t)