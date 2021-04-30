import sys
input=sys.stdin.readline

for i in range(int(input())):
	t=input().rstrip()
	print(t[0]+t[-1])