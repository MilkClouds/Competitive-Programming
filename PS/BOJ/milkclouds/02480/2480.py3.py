m=0
for i in range(1):
	a,b,c=map(int,input().split())
	if a==b==c:
		n=(10000+a*1000)
	elif len(set([a,b,c]))==2:
		if a==b:t=a
		elif a==c:t=a
		else:t=b
		n=1000+t*100
	else: n=max([a,b,c])*100
	m=max(m,n)
print(m)