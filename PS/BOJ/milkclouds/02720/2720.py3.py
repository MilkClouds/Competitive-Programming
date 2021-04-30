def t(i):
	global money
	a=money;money%=i
	return a//i
for _ in range(int(input())):
	money=int(input())
	print(*[t(i) for i in (25,10,5,1)])