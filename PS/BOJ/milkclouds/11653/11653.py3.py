n=int(input())
while n!=1:
	for e in range(2,n+1):
		if n%e==0: n//=e; print(e); break