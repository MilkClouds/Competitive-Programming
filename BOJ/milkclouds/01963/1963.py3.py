arr=[1]*10000;pn=[2]
for i in range(3,10000,2):
	if not arr[i]: continue
	pn.append(i)
	for e in range(i*i,10000,2*i):
		arr[e]=0

pn=list(filter(lambda x:x>1000,pn))

p=[0]*10000
for i in pn: p[i]=1
pn=p

import sys
from collections import deque
input()
for i in sys.stdin:
	a,b=map(int,i.split())
	q=deque()
	q.append(a);index=0
	visited=[0]*10000
	visited[a]=1
	while b not in q:
		index+=1
		for i in range(len(q)):
			cur=q.popleft()
			scur=list(map(int,str(cur)))
			for i in range(4):
				for j in range(10):
					if i==0 and j==0: continue
					scu=scur.copy()
					scu[i]=j
					num=scu[0]*1000+scu[1]*100+scu[2]*10+scu[3]
					if visited[num]: continue
					if pn[num]:
						q.append(num)
						visited[num]=1
		if not q: print('IMPOSSIBLE'); exit()
	print(index)