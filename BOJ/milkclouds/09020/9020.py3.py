import sys
input=sys.stdin.readline

def isprime(n):
	if n in (0,1): return 0
	if n in (2,3): return 1
	if n%6 in (1,5):
		for i in range(2,int(n**(1/2))+1):
			if n%i==0:
				p[n]=0
				return 0
		p[n+n::n]=[0]*((len(p)-1)//n-1)
		return 1
	p[n]=0
	return 0

p=[0,0,1,1]+[1]*(10000-3)

for i in range(2,10000+1):
	if p[i]==1: isprime(i)

for i in range(int(input())):
	i=int(input())
	for a in range(i//2,i+1):
		if p[a]:
			b=(i-a)
			if p[b]:
				print(b,a)
				break