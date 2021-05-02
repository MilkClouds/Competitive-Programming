n=int(input())

for i in range(n):
	print(' '*(n-i-1),end='')
	if i==0: t='*'
	else: t='*'+' '*(1+2*(i-1))+'*'
	print(t)