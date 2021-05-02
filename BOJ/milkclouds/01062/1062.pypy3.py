n,k=map(int,input().split())
if k<5:
	print(0)
	exit()
k-=5
arr=[set(input())-set('antic') for i in range(n)]
from itertools import combinations as c
ret=0
f=set()
for i in arr:
	f=f|i
for i in c(f,min(len(f),k)):
	t=0
	i={}.fromkeys(i)
	for j in arr:
		no=0
		for k in j:
			if i.get(k,1):
				no=1
				break
		if not no:t+=1
	ret=max(ret,t)
print(ret)