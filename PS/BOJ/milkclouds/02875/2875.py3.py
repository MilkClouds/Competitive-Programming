N,M,K=map(int,input().split())

def m(a,b):
	if a>=2*b: return b
	else: return a//2

r=0
for i in range(K+1):
	a,b=N-i,M-(K-i)
	r=max(r,m(a,b))
print(r)