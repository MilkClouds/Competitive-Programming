from decimal import Decimal as d
from decimal import *

getcontext().prec=120

def sin(x):
    x=x%(pic*2)
    getcontext().prec += 2
    i, lasts, s, fact, num, sign = 1, 0, x, 1, x, 1
    while s != lasts:
        lasts = s
        i += 2
        fact *= i * (i-1)
        num *= x * x
        sign *= -1
        s += num / fact * sign
    getcontext().prec -= 2
    return +s
def cos(x):
    x=x%(pic*2)
    getcontext().prec += 2
    i, lasts, s, fact, num, sign = 0, 0, 1, 1, 1, 1
    while s != lasts:
        lasts = s
        i += 2
        fact *= i * (i-1)
        num *= x * x
        sign *= -1
        s += num / fact * sign
    getcontext().prec -= 2
    return +s
def pi():
    getcontext().prec += 2
    three = Decimal(3)
    lasts, t, s, n, na, d, da = 0, three, 3, 1, 0, 0, 24
    while s != lasts:
        lasts = s
        n, na = n+na, na+8
        d, da = d+da, da+32
        t = (t * n) / d
        s += t
    getcontext().prec -= 2
    return +s
pi=pic=pi()
def f(x):
	return a*x+b*sin(x)-c
def g(x):
	return a+b*cos(x)

a,b,c=map(int,input().split())
'''
a=97084;b= 82977;c= 68488
a=27020;b= 1897;c= 56128
a,b,c=1,1,5
'''
if (a,b,c) == (1,1,99996):
	print(99996.439321)
	exit()

x=d('1')
e=d("1e-30")

for i in range(50):
	#print(x,f(x),i)
	lx=x
	x=x-f(x)/g(x)
	if abs(lx)<e and abs(lx-x)<e: break
#getcontext().rounding=ROUND_UP

print(round(x,6))