import sys
input=sys.stdin.readline

n=int(input())
for i in range(n):
	a,b=zip(*[map(int,input().split()) for i in range(9)])
	if sum(a)>sum(b):
		print('Yonsei')
	elif sum(a)<sum(b):
		print('Korea')
	else: print('Draw')
