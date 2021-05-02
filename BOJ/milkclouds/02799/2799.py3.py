m,n=map(int,input().split())
g=[]
for _ in range(5*m+1):
	g.append(input())
ret=[0]*5
for i in range(m):
	for j in range(n):
		t=0
		for k in range(4):
			t+=1 if '*'==g[5*i+k+1][5*j+1] else 0
		ret[t]+=1
print(*ret)