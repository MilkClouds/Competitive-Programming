def rev(n):
	return (10**len(str(n)))-n-1
for _ in range(int(input())):
	n=int(input())
	t=min(n,5*(10**(len(str(n))-1)))
	print(t*rev(t))