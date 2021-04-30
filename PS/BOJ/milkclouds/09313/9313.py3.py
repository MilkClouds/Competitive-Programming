import sys
i=sys.stdin.readline
while 1:
	n=int(i())
	if n==-1:break
	t=bin(n)[2:][::-1]
	print(int(t+'0'*(32-len(t)),2))