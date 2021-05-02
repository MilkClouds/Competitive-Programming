from collections import deque
n,k=map(int,input().split())
if n>k:
    print(n-k)
    print(*range(n,k-1,-1))
    exit()
deq=deque()
MAX=130000
visit=[False]*(MAX+1)
prev=[-1]*(MAX+1)
visit[n]=True;deq.append((n,0))
while deq:
    n,c=deq.popleft()
    if n==k:break
    for i in [n+1,n-1,n*2]:
        if not (0<=i<=MAX):continue
        if visit[i]:continue
        visit[i]=True
        deq.append((i,c+1))
        prev[i]=n
print(c)
r=[]
while k!=-1:
    r.append(k)
    k=prev[k]
print(*r[::-1])