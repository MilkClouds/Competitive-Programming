# +1, +2, -1

n=int(input())
if n<3:
    print(1)
    exit()
MOD=int(1e9)+9

dp=[0]*n
dp[0]=dp[1]=dp[2]=1
for i in range(3,n):
    dp[i]=(dp[i-1]+dp[i-3])%MOD
print((dp[-1]+dp[-3])%MOD)