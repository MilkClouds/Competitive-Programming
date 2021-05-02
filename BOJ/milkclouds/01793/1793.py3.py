import sys
d=[1,1,3];dl=2
for n in map(int,sys.stdin):
	for i in range(dl+1,n+1):
		d.append(d[i-1]+2*d[i-2])
		dl=n
	print(d[n])