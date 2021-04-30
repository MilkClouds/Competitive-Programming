n,m=map(int,[input(),input()])
for i in range(100):
	if (n//100*100+i)%m==0: print('%02d'%i);exit()