n=int(input())

h=(n-1)*4+1
ret=[[' ']*h for i in range(h)]

def func(x,y,lv):
	for i in range(lv):
		ret[x+i][y]='*'
		ret[x+i][y+lv-1]='*'
		ret[x][y+i]='*'
		ret[lv-1+x][y+i]='*'

mid=(n-1)*2
for i in range(n):
	i+=1
	t=mid-(i-1)*2
	func(t,t,(i-1)*4+1)

for i in ret:
	print(*i,sep='')