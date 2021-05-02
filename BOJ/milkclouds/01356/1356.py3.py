n=list(map(int,input()))
for i in range(len(n)-1):
	a=1
	b=1
	for j in range(i+1):
		a*=n[j]
	for j in range(i+1,len(n)):
		b*=n[j]
	if a==b:print('YES');exit()
print('NO')