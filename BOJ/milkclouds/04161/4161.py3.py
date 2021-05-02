from collections import deque
import sys
sys.setrecursionlimit(10**8)

dir=((1,2),(2,1))
dist=[[0]*100 for _ in range(100)]

Q=deque()
Q.append((0,0))
dist[0][0]=1

while Q:
    x,y = Q.popleft()
    for i in range(2):
        for j in [-1,1]:
            for k in [-1,1]:
                nx = x + dir[i][0]*j
                ny = y + dir[i][1]*k
                if abs(nx) < 100 and abs(ny) < 100:
                    if dist[abs(nx)][abs(ny)]: continue
                    dist[abs(nx)][abs(ny)]=dist[abs(x)][abs(y)]+1
                    Q.append((nx,ny))

def solve(x,y):
    x=abs(x); y=abs(y)
    if x<y: x,y=y,x
    if x<100 and y<100:
        return dist[x][y]-1
    if y==0:
        k = max((x - 10) // 4, 1)
        return solve(x - 4 * k, y) + k * 2
    if x < y + 3:
        k = max((y - 10) // 3, 1)
        return solve(x - k * 3, y - 3 * k) + k * 2
    k = min(x - y, y)
    return solve(x-k*2,y-k)+k

while 1:
    t=input()
    if t=="END":break
    a,b=map(int,t.split())
    print(solve(a,b))
