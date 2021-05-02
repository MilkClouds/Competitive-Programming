from decimal import Decimal as d
a,b,c=map(d,input().split())

s=(a+b+c)/2
S=(s*(s-a)*(s-b)*(s-c)).sqrt()
R=a*b*c/4/S
r=S/s
d=(abs(R*R-2*R*r)).sqrt()
print(S)
print(R)
print(r)
print(d)
ret=0
for i in ('a','b','c'):
	ret+=(R*R-(eval(i)/2)**2).sqrt()
print(ret)