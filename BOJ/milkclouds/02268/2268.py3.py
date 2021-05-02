import sys
input=sys.stdin.readline

def query(u)->int:
    ret=0
    while u:
        ret+=tree[u]
        u&=u-1
    return ret

def update(u,diff)->None:
    while u<=N:
        tree[u]+=diff
        u+=u&-u

N,M=map(int,input().split())
A=[0]*1000001;tree=[0]*1000001
for _ in range(M):
    a,b,c=map(int,input().split())
    if a:
        update(b,c-A[b])
        A[b]=c
    else:
        if b>c:b,c=c,b
        print(query(c)-query(b-1))