s=input()

a=0
b=0
x=0
y=0
for i in s:
	if i=='J':
		a=1
		b=0
	elif i=='O':
		a=2 if a==1 else 0
		b=2 if b==1 else 0
	elif i=='I':
		if a==2:
			x+=1
		if b==2:
			y+=1
		a=0
		b=1
	else:
		a=0
		b=0
print(x)
print(y)