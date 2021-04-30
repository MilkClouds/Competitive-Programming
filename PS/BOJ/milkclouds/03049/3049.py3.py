n=int(input())
fac=[1,1]
for i in range(2,101):
	fac.append(fac[i-1]*i)
def p(a,b):
	return fac[a]//fac[a-b]
def c(a,b):
	return p(a,b)//fac[b]

ret=c(n,4)
print(ret)