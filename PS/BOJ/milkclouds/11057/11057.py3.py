n=int(input())
d=[[1]*10]
for e in range(1,n):
	d.append([sum(d[e-1][:i+1])%10007 for i in range(10)])
print(sum(d[n-1])%10007)