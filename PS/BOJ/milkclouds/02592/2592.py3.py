a=list(map(int,[input() for i in range(10)]))

print(sum(a)//10)

d={}
for i in a:
	d[i]=d.get(i,0)+1
r=sorted(d.items(),key=lambda x:x[1])
print(r[-1][0])