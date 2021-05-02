a,b=map(int,input().split())
if a>=b:
	a,b=b,a
print(b-a-1 if a!=b else 0)
if a!=b:
	print(*range(a+1,b))