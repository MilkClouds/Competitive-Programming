import sys
input()
for line in sys.stdin:
	A,n=map(int,line.split())
	b=[]
	while A:
		b.append(A%n)
		A//=n
	print(int(b==b[::-1]))