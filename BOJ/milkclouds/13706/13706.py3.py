d=int(input())

l=0
r=10**402
while l<=r:
	m=(l+r)//2
	if m**2>d:
		r=m-1
	elif m**2<d:
		l=m+1
	else:
		print(m)
		exit()