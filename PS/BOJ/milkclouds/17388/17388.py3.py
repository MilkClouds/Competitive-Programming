a,b,c=map(int,input().split())
x=['Soongsil', 'Korea', 'Hanyang']
if a+b+c>=100:
	print('OK')
else:
	print(x[[a,b,c].index(min(a,b,c))])