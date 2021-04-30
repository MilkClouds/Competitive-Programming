x,y=map(int,input().split())
t=int(input())

if t>x*y:print(0);exit()

proc=((0,1),(1,0),(0,-1),(-1,0))
a,b=[0]*2;c=1;vec=0
m=[[0]*y for i in range(x)]
while 1:
	if c==t: break
	aa,bb=a+proc[vec][0],b+proc[vec][1]
	if 0<=aa<x and 0<=bb<y:
		if m[aa][bb]:vec=(vec+1)%4;continue
		c+=1
		m[a][b]=1
		a,b=aa,bb
	else:
		vec=(vec+1)%4
print(1+a,1+b)