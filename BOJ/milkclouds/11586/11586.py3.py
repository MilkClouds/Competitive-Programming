n=int(input())
g=[input() for _ in range(n)]
k=int(input())
if k==1:
	[*map(print,g)]
elif k==2:
	[print(i[::-1]) for i in g]
else:
	[*map(print,g[::-1])]