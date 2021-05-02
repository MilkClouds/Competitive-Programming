import sys
input=sys.stdin.readline

while 1:
	n=int(input())
	if n==0:break
	flag=0
	if n<0:
		flag=1
		n=-n
	s=0
	for i in range(1,32):
		if flag and i%2==0:continue
		if round(n**(1/i))**i==n:
			s=i
	print(s)