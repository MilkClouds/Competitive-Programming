import sys
from decimal import Decimal as dec
from decimal import *
input=sys.stdin.readline

getcontext().prec=80
d={}
for i in range(int(input())):
	a,b,c=map(int,input().split())
	x=(a**2+b**2)/dec(c)**2
	d[x]=d.get(x,[])+[i+1]

for i in sorted(d):
	print(*sorted(d[i]),sep='\n')