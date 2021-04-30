def lower(a,x):
	start=-1;end=len(a)
	if end==0:return 0
	while(start+1<end):
		mid=(start+end)//2
		if a[mid]>x:
			end=mid
		else:
			start=mid
	return start+1


a=[]

import sys
input=sys.stdin.readline
for _ in range(int(input())):
	t=map(int,input().split())
	if next(t)==0:
		print(a.pop(-1) if a else -1)
	else:
		for i in t:
			a.insert(lower(a,i),i)