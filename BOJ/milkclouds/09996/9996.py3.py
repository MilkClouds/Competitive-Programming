import re
n=int(input())
p=re.compile(input().replace('*','.*')+'$')
for i in range(n):
	t=re.match(p,input())
	print('DA' if t else 'NE')