import sys
input=sys.stdin.readline
while 1:
	t=input()[:-1]
	if t=='#': exit()
	s=0
	for i,j in enumerate(t):
		if j.isalpha():s+=(i+1)*(ord(j)-64)
	print(s)