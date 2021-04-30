n=int(input())
m=int(input())

a=''
b=''
while n and m:
	x,y=n%10,m%10
	if x==y:
		a=str(x)+a
		b=str(x)+b
	elif x>y:
		a=str(x)+a
	else:
		b=str(y)+b
	n//=10
	m//=10
if n:
	a=str(n)+a
if m:
	b=str(m)+b
print(int(a) if a else 'YODA')
print(int(b) if b else 'YODA')