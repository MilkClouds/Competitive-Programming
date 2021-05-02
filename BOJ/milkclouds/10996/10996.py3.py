n=int(input())

for i in range(n*2):
	print((' ' if i&1 else '')+' '.join('*'*(n//2)+('' if not n&1 or i&1 else '*')))