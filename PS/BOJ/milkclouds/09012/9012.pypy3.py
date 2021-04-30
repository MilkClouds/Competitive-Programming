N=int(input())
for i in range(N):
	s=input()
	p=0; n=0
	for i in s:
		p+=1 if (i=='(') else -1
		if p<0: n=1; break
	if (p!=0): n=1
	print('NO' if n else 'YES')