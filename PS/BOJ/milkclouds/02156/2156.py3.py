import sys;input=sys.stdin.readline
n=int(input())
eat=[int(input()) for i in range(n)]
if n==1: print(max(eat)); exit()
d=[[eat[0],0],[eat[1],sum(eat[:2])]]
for i in range(2,n):
	t=max(max(d[:i-1],key=max))+eat[i]
	r=d[i-1][0]+eat[i]
	d.append([t,r])
print(max(max(d,key=max)))