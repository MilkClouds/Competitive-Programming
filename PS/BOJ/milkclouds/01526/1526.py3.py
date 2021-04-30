from itertools import product
a=[]
for i in range(1,7):
	for j in product((4,7),repeat=i):
		t=sum([y*10**x for x,y in enumerate(j)])
		a.append(t)
a.sort()

n=int(input())
for i in range(len(a)):
	if a[i]>n:
		print(a[i-1])
		exit()
print(a[i])