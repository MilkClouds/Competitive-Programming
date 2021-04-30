a,b=map(int,input().split())
ret=1
for i in range(a,b+1):
	ret*=i*(i+1)//2
	ret%=14579
print(ret)