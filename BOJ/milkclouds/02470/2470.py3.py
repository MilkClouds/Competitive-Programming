import sys;input=sys.stdin.readline
from bisect import *

N=int(input())
A=sorted(map(int,input().split()))

if A[0]>=0:
    print(A[0],A[1])
    exit()
if A[-1]<=0:
    print(A[-2],A[-1])
    exit()

s=0
e=N-1
ans=10**10
deg=[]
while s<e:
	if abs(A[s]+A[e])<ans:
		ans=abs(A[s]+A[e])
		deg=(A[s],A[e])
	if A[s]+A[e]>0:
		e-=1
	else:
		s+=1
print(*deg)