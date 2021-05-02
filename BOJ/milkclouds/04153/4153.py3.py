import sys;input=sys.stdin.readline

while 1:
	i=input().rstrip()
	if i=='0 0 0':exit()
	x=sorted(map(int,i.split()))
	if x[0]**2+x[1]**2==x[2]**2:print('right')
	else: print('wrong')