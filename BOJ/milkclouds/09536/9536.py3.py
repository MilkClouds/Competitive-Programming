import sys
input=sys.stdin.readline


r='''1
toot woof wa ow ow ow pa blub blub pa toot pa blub pa pa ow pow toot
dog goes woof
fish goes blub
elephant goes toot
seal goes ow
what does the fox say?'''.split('\n')
r=iter(r)
#def input():
#	return next(r)

for i in range(int(input())):
	t=input().split()
	while 1:
		l=input().split()
		if len(l)!=3:break
		c=l[2]
		for i in range(t.count(c)):
			t.remove(c)
	print(*t)