n,a,b=map(int,input().split())

d=list(range(1,n+1))
d[a-1]=-1
d[b-1]=-1
idx=0

while 1:
	idx+=1
	if len(d)&1:
		d.append(100000)
	d=list(map(min,*2*[iter(d)]))
	if d.count(-1)==1: print(idx);exit()
print(-1)