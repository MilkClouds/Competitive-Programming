import sys
input=sys.stdin.readline
while 1:
	xx,yy=input().rstrip(),input().rstrip()
	if xx==yy=='E':break
	a=0;b=0
	for x,y in zip(xx,yy):
		if x=='R':
			if y=='P':
				b+=1
			elif y=='S':
				a+=1
		elif x=='S':
			if y=='R':
				b+=1
			elif y=='P':
				a+=1
		elif x=='P':
			if y=='S':
				b+=1
			elif y=='R':
				a+=1
	print('P1:',a)
	print('P2:',b)