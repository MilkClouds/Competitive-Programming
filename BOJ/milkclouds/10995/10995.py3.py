n=int(input())
for i in range(n):
	print((' ' if i&1 else '')+' '.join('*'*n))
