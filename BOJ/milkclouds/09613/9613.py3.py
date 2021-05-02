import sys
ii=sys.stdin.readline
from math import gcd
for _ in range(int(ii())):
	ret=0
	a=list(map(int,ii().split()))
	n,a=a[0],a[1:]
	for i in range(n):
		for j in range(i+1,n):
			ret+=gcd(a[i],a[j])
	print(ret)