import sys
input=sys.stdin.readline

fib=[1,1,2,4]
for i in range(4,68):
	fib.append(sum(fib[i-4:i]))
n=int(input())
for i in range(n):
	print(fib[int(input())])