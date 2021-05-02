n=int(input())
d=[]
for _ in range(n):
	d.append(tuple(map(int,input().split())))

def dfs(pos):
	ret=0
	for i in range(pos,n):
		c,r=d[i]
		if i+c<=n:
			ret=max(ret,dfs(i+c)+r)
	return ret

t=dfs(0)
print(t)