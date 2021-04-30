import sys
input=sys.stdin.readline

N=int(input())
A=[];B=[];prev=-1
for i in map(int,input().split()):
    if i==prev:
        continue
    A.append(i)
    B.append((i,len(B)))
    prev=i
N=len(A)

if N==1:
    print(1 if A[0] else 0)
    exit()

B.sort(reverse=1)
cur=0;res=1
for i in range(len(B)):
    idx=B[i][1]
    if idx==0:
        if A[idx]>A[idx+1]:
            cur+=1
    elif idx==N-1:
        if A[idx-1]<A[idx]:
            cur+=1
    else:
        if A[idx-1]<A[idx] and A[idx]>A[idx+1]:
            cur+=1
        elif A[idx-1]>A[idx] and A[idx]<A[idx+1]:
            cur-=1
    if i==len(B)-1 or B[i][0]!=B[i+1][0]:
        res=max(res,cur)
print(res)