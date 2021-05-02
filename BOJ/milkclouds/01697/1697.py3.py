n,m=map(int,input().split())

from collections import deque
q=deque([n]);qlen=1

index=0
visited=[0]*140001
tt=0
while 1:
	for i in range(qlen):
		cur=q.popleft(); qlen-=1
		if m==cur: tt=1;break
		if cur>0 and not visited[cur-1]:
			q.append(cur-1)
			qlen+=1
			visited[cur-1]=1
		if cur<100000 and not visited[cur+1]:
			q.append(cur+1)
			qlen+=1
			visited[cur+1]=1
		if cur<=50250 and not visited[cur*2]:
			q.append(cur*2)
			qlen+=1
			visited[cur*2]=1
	if tt:break
	index+=1

print(index)