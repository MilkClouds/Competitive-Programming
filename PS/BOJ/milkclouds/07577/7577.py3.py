import sys
input=sys.stdin.readline
K,N=map(int,input().split())
d=[[10**9]*42 for _ in range(42)]
for i in range(K):
    d[i][i+1]=1
    d[i+1][i]=0
for _ in range(N):
    x,y,r=map(int,input().split())
    if d[x-1][y]>r: d[x-1][y]=r
    d[y][x-1]=-r
for m in range(K+1):
    for s in range(K+1):
        for e in range(K+1):
            d[s][e]=min(d[s][e],d[s][m]+d[m][e])
for k in range(K+1):
    if d[k][k]<0:
        print("NONE")
        break
else:
    [print('#' if d[0][i]-d[0][i-1] else '-',end='') for i in range(1,K+1)]