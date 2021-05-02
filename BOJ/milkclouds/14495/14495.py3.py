n=int(input())
d=[1]*4
for i in range(4,n+1):
	d.append(d[i-1]+d[i-3])
print(d[n])