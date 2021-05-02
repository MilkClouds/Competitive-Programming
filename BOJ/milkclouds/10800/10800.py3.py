import sys
input=sys.stdin.readline
N=int(input())
balls=[];ans=[0]*N
for idx in range(N):
    i,j=map(int,input().split())
    balls.append((j,i,idx))
balls.sort()

Sum=[0]*(N+2)
lazy=[0]*(N+2)
lazkey=-1
for i in range(N):
    s,c,idx=balls[i]
    if lazkey!=s:
        lazy=[0]*(N+2)
        lazkey=s
    ans[idx]=Sum[-1]-Sum[c]-(lazy[-1]-lazy[c])
    Sum[c]+=s
    Sum[-1]+=s
    lazy[c]+=s
    lazy[-1]+=s
print(*ans,sep='\n')