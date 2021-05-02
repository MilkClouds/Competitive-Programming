arr=[True]*1000;pn=[2]
for i in range(3,1000,2):
	if arr[i]:
		pn.append(i)
		for j in range(i*i,1000,i*2):
			arr[j]=False
pnd={}.fromkeys(pn)
isprime=lambda x:not pnd.get(x,True)
def func(n):
	if isprime(n):
		return n-1
	fac={};t=n
	for i in pn:
		while t%i==0:
			fac[i]=fac.get(i,0)+1
			t//=i
	if len(fac)==1:
		p=next(iter(fac))
		return n//p*(p-1)
	else:
		r=1
		for i in fac:
			r*=ff(i**fac[i])
		return r
fsave=[0]*1001
def ff(n):
	if fsave[n]==0:
		fsave[n]=func(n)
	return fsave[n]
import sys;input=sys.stdin.readline
for _ in range(int(input())):
	N=int(input())
	r=2
	for i in range(1,1+N):
		if i==1:
			r+=1
		else:
			r+=ff(i)*2
	print(r)