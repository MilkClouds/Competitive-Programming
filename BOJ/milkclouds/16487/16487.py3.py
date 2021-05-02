from decimal import Decimal as d
def S(a,b,c):
	s=(a+b+c)/2
	return (s*(s-a)*(s-b)*(s-c)).sqrt()

a,b,c=map(d,input().split())
m=d(input())

print(a**2+m**2-2*a*m*(a**2+b**2-c**2)/(2*a*b))