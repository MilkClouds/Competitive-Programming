a,b,c=input().split()

d=['+','-','*','/']
for i in d:
	if eval(b+i+c)==eval(a): print(a+'='+b+i+c);exit()
	if eval(a+i+b)==eval(c): print(a+i+b+'='+c);exit