import sys
input=sys.stdin.readline
for i in range(int(input())):
	print('Case #%d:'%(i+1),*input().split()[::-1])