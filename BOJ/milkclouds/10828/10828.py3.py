import sys
input=sys.stdin.readline
N=int(input())
stack=[]
for i in range(N):
	inp=input().split()
	if inp[0][0]=='t':
		if stack:
			print(stack[-1])
		else: print(-1)
	elif inp[0][0]=='e':
		print(0 if stack else 1)
	elif inp[0][1]=='o':
		if stack:
			print(stack.pop())
		else: print(-1)
	elif inp[0][1]=='u':
		stack.append(inp[1])
	else:
		print(len(stack))