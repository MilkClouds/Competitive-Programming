n=int(input())
r=[]
for i in range(n):
	r.append(list(reversed(input().split())))
r.sort()
for i in r:
	print(*reversed(i))