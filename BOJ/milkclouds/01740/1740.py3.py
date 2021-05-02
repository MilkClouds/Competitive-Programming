from decimal import Decimal as d
from math import log2

n=int(input())

num=n;ret=0
while num:
	level=int(log2(num))
	if num==1: level=0
	ret+=3**level
	num=num-(1<<(level))
print(ret)