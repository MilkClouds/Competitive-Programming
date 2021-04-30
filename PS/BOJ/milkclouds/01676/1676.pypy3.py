n=int(input())
r=1;bi=[0,0]
for i in range(2,n+1):
	t=i
	while 1:
		if t%2==1: break
		t//=2
		bi[0]+=1
	t=i
	while 1:
		if t%5!=0: break
		t//=5
		bi[1]+=1
print(min(bi))	