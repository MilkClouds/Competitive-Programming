def G(a,b):
    if a<b: a,b=b,a
    if b==0: return a
    while a%b:
        a,b=(b,a%b)
    return b
def L(a,b):
 return a*b//G(a,b)

n=int(input())
A=[]
for i in range(n):
	A.append(int(input()))
A.sort()
def GS(A):
	if len(A)==1: return A[0]
	g=G(A[0],A[1])
	for i in A[2:]:
		g=G(g,i)
	return g
D=[A[i+1]-A[i] for i in range(n-1)]
M=[]; d=GS(D)
for i in range(2,d+1):
	if d%i==0: M.append(i)

print(' '.join(map(str,M)))