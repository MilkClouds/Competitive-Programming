def G(a,b):
	if a<b: a,b=b,a
	if a%b==0: return b
	return G(a%b,b)
def L(a,b):
	return a*b//G(a,b)


N=int(input())
for i in range(N):
	k,n=[int(i) for i in input().split(' ')]
	print(L(k,n))
