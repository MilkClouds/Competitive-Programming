import sys,time
input=sys.stdin.readline

M=5*10**6
arr=[True]*M
factor=[0]*(M+1)
pn=[2]
for i in range(3,M,2):
    if arr[i]:
        pn.append(i)
        for j in range(i**2,M,i*2):
            arr[j]=False
            if factor[j]==0:
                factor[j]=i

for i in pn:
    factor[i]=i

def solution(n):
    ret=[]
    while n%2==0:
        n//=2
        ret.append(2)
    while n>1:
        ret.append(factor[n])
        n//=factor[n]
    return ret

input()
for n in map(int,input().split()):
    t=solution(n)
    for i in t:
        sys.stdout.write(str(i)+' ')
    sys.stdout.write('\n')