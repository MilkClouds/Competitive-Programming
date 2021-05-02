D=[[],[1,0,0],[0,1,0],[1,1,1]]
mod=1000000009

for i in range(4,10**5+1):
	x=sum(D[i-1][1:])%mod
	y=sum((D[i-2][0],D[i-2][2]))%mod
	z=sum(D[i-3][:2])%mod
	D.append([x,y,z])
for _ in range(int(input())): print(sum(D[int(input())])%mod)