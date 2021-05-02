dp=[0]*5005;l=0;MOD=10**6;dp[0]=1
for idx,i in enumerate(map(int,input())):
    if l==i==0 or (not (0<l<3) and i==0):
        print(0)
        exit()
    if 0<l<3 and l*10+i<27:
        dp[idx+1]+=dp[idx-1]
    if i:
        dp[idx+1]+=dp[idx]
    dp[idx+1]%=MOD
    l=i
print(dp[idx+1])