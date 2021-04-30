A=list(range(1,21))
for _ in range(10):
	a,b=map(lambda x:int(x)-1,input().split())
	A[a:b+1]=A[a:b+1][::-1]
print(*A)