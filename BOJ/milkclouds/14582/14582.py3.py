a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=d=yeok=0
for i,j in zip(a,b):
	c+=i
	if c>d:
		yeok=1
	d+=j
if yeok and c<d: print('Yes')
else:print('No')