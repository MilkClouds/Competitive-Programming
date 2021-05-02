import sys;input=sys.stdin.readline;print=sys.stdout.write
from bisect import *
import math
for _ in range(int(input())):
	m=int(input())
	idx=0
	print(str((m+1)//2)+'\n')
	a=[]
	for t in range(math.ceil(m/10)):
		for i in map(int,input().split()):
			idx+=1
			insort(a,i)
			if idx&1:
				print(str(a[(idx+1)//2-1])+' ')
		if t&1:
			print('\n')
	if t%2==0:
		print('\n')