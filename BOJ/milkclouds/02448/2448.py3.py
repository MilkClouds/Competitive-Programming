import sys,math
dd=[[' ',' ','*',' ',' '],[' ','*',' ','*',' '],'*'*5]
n=int(input())
k=int(math.log2(n//3))
ret=[[' ']*(n*2) for _ in range(n)]
def apply(x,y):
	for i in range(3):
		for j in range(5):
			ret[y+i][x+j]=dd[i][j]
def rec(x,y,size):
	if size==0:
		apply(x,y)
		return
	var=3*(2**size)//2
	rec(x+var,y,size-1)
	rec(x,y+var,size-1)
	rec(x+2*var,y+var,size-1)
rec(0,0,k)
for i in ret:
	sys.stdout.write(''.join(i)+'\n')
