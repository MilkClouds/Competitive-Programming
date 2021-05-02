x,y,z,w=map(int,input().split())
for i in range(w//x+1):
	re=w-x*i
	for j in range(re//y+1):
		re2=re-y*j
		if re2%z==0: print(1);exit()
print(0)