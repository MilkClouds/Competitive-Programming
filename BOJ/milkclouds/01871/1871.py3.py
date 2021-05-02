import sys
input=sys.stdin.readline

d={}
for i in range(26):
	d[chr(65+i)]=i
for i in range(int(input())):
	a,b=input().split('-')
	n=0
	for i,data in enumerate(a[::-1]):
		n+=26**i*d[data]
	if abs(int(b)-n)>100: print('not nice')
	else: print('nice')