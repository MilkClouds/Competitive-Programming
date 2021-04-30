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
		p[n+n::n]=[0]*(len(p)//n-1)
		return 1
	p[n]=0
	return 0

p=[0,0,1,1]+[1]*(123456*2-3)

for i in range(2,123456*2):
	if p[i]==1: isprime(i)

while 1:
	i=int(input())
	if i==0: break
	print(sum([p[a] for a in range(i+1,2*i+1)]))