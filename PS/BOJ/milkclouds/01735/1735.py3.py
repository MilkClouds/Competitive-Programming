
a,b=map(int,input().split())
c,d=map(int,input().split())

r=a*d+b*c
e=b*d

x,y=r,e
if x<y:x,y=y,x
while x%y:
	x,y=y,x%y
print(r//y,e//y)