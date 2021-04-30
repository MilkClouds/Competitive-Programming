import sys
input=sys.stdin.readline
i=sys.stdin.read
for _ in range(int(input())):
	a=''
	while 1:
		inp=i(1)
		if inp==' ': break
		a+=inp
	s=0
	while 1:
		inp=input(100000)
		s+=sum(map(int,inp.rstrip()))
		if inp[-1]=='\n': break
	print(s%(int(a)-1))
	