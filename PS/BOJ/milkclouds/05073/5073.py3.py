while 1:
	a,b,c=sorted(map(int,input().split()))
	if a==b==c==0:break
	if a+b<=c:
		print('Invalid');continue
	if a==b==c:
		print('Equilateral')
	elif len(set((a,b,c)))==2:
		print('Isosceles')
	else:
		print('Scalene')