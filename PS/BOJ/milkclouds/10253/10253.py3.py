import sys
from fractions import Fraction as f
input=sys.stdin.readline

for _ in range(int(input())):
	a,b=map(f,input().split())
	ff=f(a)/b
	x=[]
	while 1:
		a,b=ff.numerator,ff.denominator
		xx=b//a+1 if b%a else b//a
		ff-=1/f(xx)
		# x.append(xx)
		if ff<=0:break
	print(xx)