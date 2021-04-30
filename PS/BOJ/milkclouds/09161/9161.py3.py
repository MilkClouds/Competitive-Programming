from math import gcd
from fractions import Fraction as f


for i in range(100,1000):
	for j in range(1,100):
		c=i%10
		aa=f(i)/f(c*100+j)
		bb=f(i//10)/f(j)
		if len(set(str(i)))==1:continue
		if aa==bb:
			print('%d / %d = %d / %d'%(i,c*100+j,i//10,j))