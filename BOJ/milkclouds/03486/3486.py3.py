import sys
i=sys.stdin.readline
def f(n):
	return int(str(n)[::-1])
for _ in range(int(i())):
	a,b=map(f,map(int,i().split()))
	print(f(a+b))