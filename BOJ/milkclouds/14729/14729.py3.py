import sys;input=sys.stdin.readline;print=sys.stdout.write
from bisect import *
a=[]
for _ in range(int(input())):
	n=float(input())
	idx=bisect(a,n)
	if idx==7:
		continue
	else:
		a.insert(idx,n)
	if len(a)==8:
		a.pop(-1)
for i in a:
	print("%.3f\n"%i)