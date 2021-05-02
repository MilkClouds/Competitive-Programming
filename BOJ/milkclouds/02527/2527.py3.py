
for _ in range(4):
	t=list(map(int,input().split()))
	p=t[:4];q=t[4:]
	x=min(p[2],q[2])-max(p[0],q[0])
	y=min(p[3],q[3])-max(p[1],q[1])
	if p[:2]==q[2:] or (p[0],p[3])==(q[2],q[1]) or (p[2],p[1])==(q[0],q[3]) or p[2:]==q[:2]:
		print('c')
	elif x<0 or y<0:
		print('d')
	elif not (x and y):
		print('b')
	else:
		print('a')
		