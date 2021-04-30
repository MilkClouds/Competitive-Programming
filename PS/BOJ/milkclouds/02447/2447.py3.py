import sys
n=int(input())
a=[[' ']*n for i in range(n)]
def solve(x,y,n):
	if n==1:
		a[x][y]='*'
		return
	m=n//3
	for i in range(3):
		for j in range(3):
			if i==j==1:continue
			solve(m*i+x,y+m*j,m)
solve(0,0,n)
for i in a:
	sys.stdout.write(''.join(i)+'\n')