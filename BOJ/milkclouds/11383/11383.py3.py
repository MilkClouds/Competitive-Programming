import sys
input=sys.stdin.readline
n,m=map(int,input().split())
a=[input()[:-1] for i in range(n)]
b=[input()[:-1] for i in range(n)]
for i,j in enumerate(b):
	for x,y in enumerate(j[::2]):
		if j[x*2+1]!=y or a[i][x]!=y:
			print("Not Eyfa")
			exit()
print("Eyfa")