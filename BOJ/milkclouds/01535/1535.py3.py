n=int(input());ret=0
minus=list(map(int,input().split()))
plus=list(map(int,input().split()))
dp=[0]*100
for idx,d in enumerate(minus):
	for i in range(99,d-1,-1):
		dp[i]=max(dp[i],dp[i-d]+plus[idx])
print(dp[99])