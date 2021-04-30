import sys
input=sys.stdin.readline
for _ in range(int(input())):
	d=input()[:-1]
	r=set(d[len(d)//2-1:len(d)//2+1])
	print('Do-it'+('-Not' if len(r)==2 else ''))