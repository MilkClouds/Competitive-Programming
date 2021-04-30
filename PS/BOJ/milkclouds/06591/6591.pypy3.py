def fact(i):
 b=1
 for a in range(2,i+1):
  b*=a
 return b
def P(a,b):
	c=1
	for i in range(a,a-b,-1):
		c*=i
	return c
def C(a,b):
	if (a,b)==(0,0): sys.exit()
	b=b if a-b>b else a-b
	return P(a,b)//fact(b)
import sys
while 1: print(C(*map(int,input().split(' '))))