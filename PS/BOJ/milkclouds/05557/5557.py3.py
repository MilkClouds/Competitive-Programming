n=int(input())
dp=[[0]*21 for i in range(101)]
idx=0
for i in map(int,input().split()):
	if idx==n-1:
		last=i
	if idx:
		for j in range(21):
			if 0<=i+j<=20:
				dp[idx][i+j]+=dp[idx-1][j]
			if 0<=j-i<=20:
				dp[idx][j-i]+=dp[idx-1][j]
	else:
		dp[0][i]=1
	idx+=1
print(dp[n-2][last])