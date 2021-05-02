n=int(input())
ret=0

for i in range(1+n):
	ret+=(n-i+1)*i+n*(n+1)//2-i*(i-1)//2
print(ret)