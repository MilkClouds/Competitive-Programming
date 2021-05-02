A,B=[int(input()) for i in range(2)]

def isprime(n):
	if n in (0,1): return 0
	if n in (2,3): return 1
	if n%6 in (1,5):
		for i in range(2,int(n**(1/2))+1):
			if n%i==0:
				return 0
		return 1
	return 0

l=[]
for i in range(A,B+1):
	if isprime(i):
		l.append(i)

if l:
 print(sum(l))
 print(l[0])
else: print(-1)