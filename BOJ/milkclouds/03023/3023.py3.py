n,m=map(int,input().split())
r=[]
for i in range(n):
	t=list(input())
	r.append(t+t[::-1])
for i in range(n,0,-1):
	r.append(r[i-1].copy())
a,b=map(lambda x:int(x)-1,input().split())
r[a][b]='#' if r[a][b]=='.' else '.'

for i in r:
	print(*i,sep='')