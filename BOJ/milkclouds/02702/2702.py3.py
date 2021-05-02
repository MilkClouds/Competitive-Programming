from math import gcd
def l(a,b):
	return a*b//gcd(a,b)

import sys
input=sys.stdin.readline
for _ in range(int(input())):
	a,b=map(int,input().split())
	print(l(a,b),gcd(a,b))