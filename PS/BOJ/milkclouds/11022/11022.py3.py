import sys
input=sys.stdin.readline

N=int(input())
for i in range(N):
	l=list(map(int,input().split(' ')))
	print('Case #%d: %d + %d = %d'%(i+1,l[0],l[1],sum(l)))