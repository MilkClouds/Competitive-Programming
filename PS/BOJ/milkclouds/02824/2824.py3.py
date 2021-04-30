import sys
input=sys.stdin.readline

n=int(input())
a=1
mod=int(1e10)
for i in map(int,input().split()):
	a*=i
m=int(input())
b=1
for i in map(int,input().split()):
	b*=i
from math import gcd
print('%s'%str(gcd(a,b))[-9:])