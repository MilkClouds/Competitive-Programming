input();step=0;t=0
for i in map(int,input().split()):
	if i==1:step+=1
	else: step=0
	t+=step
print(t)