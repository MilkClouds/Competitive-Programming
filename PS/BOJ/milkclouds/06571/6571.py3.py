import sys
d=[1,2]
i=1
while 1:
	i+=1
	d.append(d[i-1]+d[i-2])
	if d[i]>1e100:break

for line in sys.stdin:
	a,b=map(int,line.split())
	if a==b==0:break
	print(len([1 for i in d if a<=i<=b]))