n=int(input())

for i in range(n):
	if i==n-1: print('*'.join('*'*(i+1))); break
	print(' '*(n-i-1),end='')
	t='*'
	t+=' '.join(' '*(i))
	if i!=0: t+='*'
#	if i==0: t='*'
#	else: t='*'+' '*(1+2*(i-1))+'*'
	print(t)