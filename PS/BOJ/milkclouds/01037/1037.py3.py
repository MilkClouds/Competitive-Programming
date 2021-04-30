input()

def G(a,b):
	if a<b: a,b=b,a
	while a%b:
		a,b=(b,a%b)
	return b
def L(a,b): return a*b//G(a,b)

def el(a):
	for i in range(2,int(a**0.5)+1):
		if a%i==0: return i
	return a

r=list(map(int,input().split()))
a=1
for i in r: a=L(a,i)

r.sort()
if r[-1]==a: a*=el(a)
print(a)