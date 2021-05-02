import sys

fac=[1,1,2];l=2
for n in map(int,sys.stdin):
	for i in range(l+1,n+1):
		t=i*fac[i-1]
		while t%10==0:
			t//=10
		fac.append(t)
		l=n
	print(' '*(5-len(str(n)))+str(n),'->',fac[n]%10)