n=int(input())

if n&1:
	print('*'*n)
	for i in range(1,n+1,2):
		print(' '*((n-i)//2) + '*' + ' '*(i-2)+('*' if i!=1 else ''))
else: print('I LOVE CBNU')