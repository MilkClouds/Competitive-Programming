import sys
for l in sys.stdin:
	if l.rstrip()=='-1': break
	t=list(map(int,l.split()[:-1]))
	r=0
	for i in t:
		if i*2 in t:
			r+=1
	print(r)