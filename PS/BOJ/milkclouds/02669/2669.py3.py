dd=[[0]*100 for i in range(100)];r=0
for i in range(4):
	a,b,c,d=map(int,input().split())
	for x in range(a,c):
		for y in range(b,d):
			if dd[x][y]: continue
			dd[x][y]=1
			r+=1
print(r)