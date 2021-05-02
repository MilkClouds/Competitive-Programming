import sys
i=sys.stdin.readline
for _ in range(int(i())):
	N, D, A, B, F=map(float,i().split())
	r=D/(A+B)*F
	print('%d %.2f'%(N,r))