import sys
for line in sys.stdin:
	r,c=map(int,line[1:].split("C"))
	if r==0==c: break
	ret=''
	while c:
		ret=chr((c-1)%26+65)+ret
		c=(c-1)//26
	print(ret+str(r))