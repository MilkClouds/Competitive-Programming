n,r=[int(i) for i in input().split(' ')]
r=r if n>2*r else n-r
P=1000000007

def power(x,y):
	if y==0: return 1
	res=1
	while y>0:
		if y%2:
			res*=x; res%=P
		x*=x; x%=P; y//=2
	return res

fac=[1,1]; inv=[]
for i in range(2,n+1):
	fac.append(fac[i-1]*i%P)
inv=[0]*(n)+[power(fac[n],P-2)]
for i in range(n-1,-1,-1):
	inv[i]=inv[i+1]*(i+1)%P

print(inv[n-r]*(inv[r]*fac[n]%P)%P)