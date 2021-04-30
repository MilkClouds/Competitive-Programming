import sys
input=sys.stdin.readline
for _ in range(int(input())):
	t=input()[:-1]
	print(*[i[::-1] for i in t.split()])