import sys;input=sys.stdin.readline

def func(dist):
    ret=0
    for i in range(1,N):
        ret+=abs(i*dist-A[i])
    return ret

N=int(input())
A=list(map(int,input().split()))

lo,hi=0,A[-1]
while hi-lo>=3:
    p,q=(lo*2+hi)//3,(lo+hi*2)//3
    if func(p)<=func(q):
        hi=q
    else:
        lo=p

ret=1<<64
for i in range(lo,hi+1):
    ret=min(ret,func(i))
print(ret)