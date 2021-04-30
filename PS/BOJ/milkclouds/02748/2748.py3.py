N=int(input())
DP=[0,1,1,2]
for i in range(4,N+1):
	DP.append(DP[i-1]+DP[i-2])
print(DP[N])