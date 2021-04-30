t=input();ret=0
for i in range(13):
	if t[i]=='*': star=i&1
	else:ret+=int(t[i])*(3 if i&1 else 1)
for i in range(10):
	if (ret+(i*3 if star else i))%10==0:
		print(i);exit()