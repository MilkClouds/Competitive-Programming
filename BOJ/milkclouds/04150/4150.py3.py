d=[1,1]
n=int(input())
for i in range(n-2):
	d.append(d[i+1]+d[i])
print(d[n-1])