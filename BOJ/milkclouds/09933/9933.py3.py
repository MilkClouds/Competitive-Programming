import sys
input=sys.stdin.readline
d=[]
for i in range(int(input())):
	m=input().rstrip()
	d.append(m)
	if m[::-1] in d: print(len(m),m[len(m)//2]);exit()