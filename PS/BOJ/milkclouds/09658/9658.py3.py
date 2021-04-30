n=int(input())
dp=[1,0,1,0]
for i in range(4,n+1):
	if 0 in (dp[i-1],dp[i-3],dp[i-4]): dp.append(1)
	else: dp.append(0)
print('SK' if dp[n] else "CY")