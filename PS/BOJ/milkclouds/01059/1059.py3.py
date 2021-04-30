import sys
input=sys.stdin.readline
n=int(input())
a=sorted(map(int,input().split()))
from bisect import *
t=int(input())
pos=bisect_left(a,t)
below=a[pos-1] if pos>0 else 0
print(max(0,(a[pos]-t)*(t-below)-1))