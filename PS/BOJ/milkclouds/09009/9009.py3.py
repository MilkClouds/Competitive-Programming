d=[0,1]

i=2
while 1:
	if d[i-1]>10**9: break
	d.append(d[i-1]+d[i-2])
	i+=1

for _ in range(int(input())):
	a=int(input())
	ret=[]
	while a>0:
		for i,j in enumerate(d):
			if j>a: break
		a-=d[i-1]
		ret.append(d[i-1])
	print(*ret[::-1])