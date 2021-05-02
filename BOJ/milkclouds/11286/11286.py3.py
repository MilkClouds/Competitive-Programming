import sys
input=sys.stdin.readline
from heapq import *
from collections import deque
rr=[]
class my:
	def __init__(self,n):
		self.n=n
	def __lt__(self,other):
		return abs(self.n)<abs(other.n) if abs(self.n)^abs(other.n) else self.n<other.n
	def __repr__(self):
		return str(self.n)
def print(t):
	sys.stdout.write(str(t)+'\n')
for _ in range(int(input())):
	t=int(input())
	if t==0:
		print(heappop(rr) if rr else 0)
	else:
		heappush(rr,my(t))