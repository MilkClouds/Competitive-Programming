def isprime(n):
	if n in (0,1): return 0
	if n in (2,3): return 1
	if n%6 in (1,5):
		for i in range(2,int(n**(1/2))+1):
			if n%i==0:
				return 0
		return 1
	return 0

input()
A=[int(i) for i in input().split(' ')]
#A=[1,4,3,6,22,23]

print(sum([isprime(i) for i in A]))