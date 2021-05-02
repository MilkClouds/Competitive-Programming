a,b=int(input()),int(input())

from math import *
def C(n,m):
	return factorial(n)//factorial(m)//factorial(n-m)
def H(n,m):
	return C(n+m-1,m)


print(H(a,b-a) if b-a>=0 else 0)