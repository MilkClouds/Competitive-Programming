n=int(input())
for i in range(n):
	print('*'*(1+i)+' '*(n-1-i),end='')
	print(' '*(n-1-i)+'*'*(1+i))

for i in range(n-2,-1,-1):
	print('*'*(1+i)+' '*(n-1-i),end='')
	print(' '*(n-1-i)+'*'*(1+i))