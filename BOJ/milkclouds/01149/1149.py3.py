N=int(input())
RGB=[list(map(int,input().split(' '))) for i in range(N)]
DP=[RGB[0]]
for i in range(1,N):
    DP.append([0]*3)
    for n in range(3):
        DP[i][n]=min(DP[i-1][(n+1)%3],DP[i-1][(n+2)%3])+RGB[i][n]
print(min(DP[N-1]))
