n,k=map(int,input().split())
a=[int(input()) for _ in range(n)]

dp=[1<<31]*10001

dp[0]=0
for i in range(n):
    for j in range(a[i],k+1):
        dp[j]=min(dp[j],1+dp[j-a[i]])

print(-1 if dp[k]==1<<31 else dp[k])