import sys
input=sys.stdin.readline

d='''PROBRAIN, GROW, ARGOS, ADMIN, ANT, MOTION, SPG, COMON, ALMIGHTY'''

d=d.split(', ')
input()
n=0
s=''
for i in d:
	t=max(map(int,input().split()))
	if t>n:
		n=t
		s=i
print(s)