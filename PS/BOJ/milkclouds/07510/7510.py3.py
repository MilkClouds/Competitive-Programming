import sys
input=sys.stdin.readline

for i in range(int(input())):
	t=list(map(int,input().split()))
	t.sort()
	print('Scenario #%d:'%(i+1))
	if sum(map(lambda x:x*x,t[:2]))==t[2]**2:
		print('yes')
	else: print('no')
	print()