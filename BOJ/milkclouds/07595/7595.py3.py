import sys
input=sys.stdin.readline
print=sys.stdout.write
while 1:
	n=int(input())
	if n==0: break
	for i in range(1,n+1):
		print('*'*i+'\n')