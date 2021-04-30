N=int(input())
DP=[0,[1,0],[0,1],[1,1]]
for i in range(4,N+1):
    DP.append([DP[i-1][1],DP[i-1][1]+DP[i-1][0]])
print(sum(DP[N]))