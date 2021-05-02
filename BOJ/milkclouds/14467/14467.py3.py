n=int(input())
ret=0
pos=[-1]*11
for i in range(n):
	t,p=map(int,input().split())
	if pos[t]==-1:
		pos[t]=p
	elif pos[t]!=p:
		pos[t]=p
		ret+=1
print(ret)