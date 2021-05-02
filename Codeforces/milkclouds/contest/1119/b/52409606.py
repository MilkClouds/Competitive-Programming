import sys;input=sys.stdin.readline
from bisect import *

N,H=map(int,input().split())
A=list(map(int,input().split()))
L=[]

for i in range(N):
    insort(L,A[i])
    if sum(L[len(L)-1::-2])>H:
        print(i)
        exit()
else:
    print(N)
