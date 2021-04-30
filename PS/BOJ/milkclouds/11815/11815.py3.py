n=int(input())
r=[]
for i in map(int,input().split()):
	r.append(1 if int(i**.5)**2==i else 0)
print(*r)