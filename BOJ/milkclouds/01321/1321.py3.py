def update(i,v):
    while i<=N:
        tree[i]+=v
        i+=i&-i
def sum(i):
    ret=0
    while i:
        ret+=tree[i]
        i^=i&-i
    return ret

import sys;input=sys.stdin.readline
N=int(input())
tree=[0]*(N+1)
for idx,i in enumerate(map(int,input().split())):
    update(idx+1,i)
for _ in range(int(input())):
    t=map(int,input().split())
    if next(t)==1:
        a,b=t
        update(a,b)
    else:
        a=next(t)
        start=1
        end=N
        while start<end:
            mid=(start+end)//2
            if sum(mid)<a:
                start=mid+1
            else:
                end=mid
        print(start)