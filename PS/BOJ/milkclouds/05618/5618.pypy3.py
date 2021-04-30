input()
t=list(map(int,input().split()))
def G(a,b):
	if a<b: a,b=b,a
	while a%b:
		a,b=b,a%b
	return b

g=0
for i,j in zip(t,t[1:]):
	s=G(i,j)
	if g: g=G(g,s)
	else: g=s

for i in range(1,g//2+1):
	if g%i==0: print(i)
print(g)