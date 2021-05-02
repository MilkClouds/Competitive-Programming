import sys
input=sys.stdin.readline
d=[350.34,230.90,190.55,125.30,180.90]
for i in range(int(input())):
	r=0
	for i,e in enumerate(map(int,input().split())):
		r+=e*d[i]
	print('$%.2f'%r)