c=1
for _ in range(int(input())):
	a,b=map(int,input().split())
	if a==c:c=b
	elif b==c:c=a
print(c)