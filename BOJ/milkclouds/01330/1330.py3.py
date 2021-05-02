a,b=input().split()
op=('>','<','==')
for i in op:
	if eval(a+i+b):print(i)