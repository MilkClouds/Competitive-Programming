a,b=map(int,input().split())
tot=0; ret=0
for i in map(int,input().split()):
	if tot+i>b: break
	tot+=i; ret+=1
print(ret)