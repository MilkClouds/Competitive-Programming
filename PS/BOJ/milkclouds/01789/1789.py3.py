n=int(input())
for i in range(1,1<<17):
	t=i*(i+1)//2
	if t>n:l=i;break
print(l-1)