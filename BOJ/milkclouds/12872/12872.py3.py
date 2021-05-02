# dp[i][j]=dp[i-1][j-1]*(n-i+1)+(dp[i][j-1] if i>M)

n,m,p=map(int,input().split())

dp=[[0]*101 for _ in range(101)]

dp[0][0]=1

for i in range(1,1+p):
    for j in range(1+n):
        if j>0:
            dp[i][j]+=dp[i-1][j-1]*(n-j+1)
        dp[i][j]+=(dp[i-1][j]*(j-m) if j>m else 0)
        dp[i][j]%=1000000007
print(dp[p][n])