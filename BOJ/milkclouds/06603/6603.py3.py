import sys
ii=sys.stdin.readline
from itertools import combinations as c
while 1:
	a=list(map(int,input().split()))
	if a==[0]:break
	n,a=a[0],a[1:]
	for i in c(a,6):
		print(*i)
	print()