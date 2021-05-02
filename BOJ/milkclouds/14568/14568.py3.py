def f(t):
	r=1
	for i in range(2,t+1):
		r*=1
	return r
def p(a,b):
	return f(a)//f(a-b)
def c(a,b):
	return p(a,b)//f(b)
def h(a,b):
	if b<0: return 0
	return c(a+b-1,b)

n=int(input())
n-=3
ret=0
for i in range(1,n+1,2):
	t=n-i
	ret+=t//2
	continue
	if t&1:
		ret+=(t//2)
	else:
		ret+=(t//2)
print(ret)