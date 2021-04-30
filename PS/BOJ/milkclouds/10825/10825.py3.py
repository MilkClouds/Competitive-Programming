import sys
input=sys.stdin.readline
a=[]
for i in range(int(input())):
	t=input().split()
	a.append([t[0]]+list(map(int,t[1:])))
a.sort(key=lambda x:x[0])
a.sort(key=lambda x:x[3],reverse=1)
a.sort(key=lambda x:x[2])
a.sort(key=lambda x:x[1],reverse=1)
for i in a: print(i[0])