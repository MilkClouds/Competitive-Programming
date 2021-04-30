import sys;input=sys.stdin.readline

d={'e':1,'o':0}
while 1:
	i=input().rstrip()
	if i=='#': exit()
	if (i.count('1')+d[i[-1]])&1: print(i[:-1]+'0')
	else: print(i[:-1]+'1')