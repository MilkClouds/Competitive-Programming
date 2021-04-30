import sys
input=sys.stdin.readline
for i in range(int(input())):
	a,b=map(int,input().split(),[2,2])
	print(str(bin(a+b))[2:])