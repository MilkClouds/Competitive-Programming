n,k=map(int,input().split())
a=[int(input()) for _ in range(n)]

dp=[0]*10001

dp[0]=1
for i in range(n):
    for j in range(a[i],k+1):
        dp[j]=dp[j]+dp[j-a[i]]

print(dp[k])