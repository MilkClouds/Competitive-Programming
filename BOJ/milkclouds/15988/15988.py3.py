D=[0,1,2,4]
mod=1000000009

for i in range(4,10**6+1):
	x=(D[i-1]+D[i-2]+D[i-3])%mod
	D.append(x)
for _ in range(int(input())): print(D[int(input())]%mod)