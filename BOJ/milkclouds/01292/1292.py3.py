a,b=map(int,input().split())
d=[]
for i in range(1,50):
	d+=[i]*i
print(sum(d[a-1:b]))