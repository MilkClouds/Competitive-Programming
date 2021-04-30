import sys
input()
for line in sys.stdin:
	t=list(map(int,line.split()))
	for i in range(4):
		t[i]+=t[i+4]
	t[0]=max(t[0],1)
	t[1]=max(t[1],1)
	t[2]=max(0,t[2])
	r=0
	for i,j in enumerate((1,5,2,2)):
		r+=t[i]*j
	print(r)