for _ in range(3):
	l=0
	m=1
	for i in input():
		if l==i:
			c+=1
			m=max(m,c)
		else:
			c=1
		l=i
	print(m)