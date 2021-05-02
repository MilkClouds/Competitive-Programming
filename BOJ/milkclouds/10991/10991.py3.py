n=int(input())

for i in range(n):
	print(' '*(n-i-1),end='')
	t=' '.join('*'*(i+1))
	print(t)