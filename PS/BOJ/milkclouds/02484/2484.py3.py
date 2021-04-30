m=0
for i in range(int(input())):
	a,b,c,d=map(int,input().split())
	l=[a,b,c,d]
	if a==b==c==d:
		n=(50000+a*5000)
	elif len(set(l))==2:
		twotwo=0
		for i in set(l):
			if l.count(i)==2: twotwo=1
		if twotwo:
			n=2000+500*sum(set(l))
		else:
			if a==b:t=a
			elif a==c:t=a
			else:t=b
			n=10000+t*1000
	elif len(set(l))==3:
		for i in set(l):
			if l.count(i)==2:
				target=i
		n=1000+100*target
	else: n=max([a,b,c,d])*100
	m=max(m,n)
print(m)