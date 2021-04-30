def dist(a,b):
	return (a[0]-b[0])**2+(a[1]-b[1])**2
for _ in range(int(input())):
	coord=list([list(map(int,input().split())) for i in range(4)])
	d=set()
	for i in range(4):
		for j in range(i+1,4):
			d.add(dist(coord[i],coord[j]))
	d=sorted(d)
	if(len(d)==2 and d[0]*2==d[1]):
		print(1)
	else:
		print(0)