import sys
input=sys.stdin.readline

n=int(input());x=y=0
for i in range(n):
	a,b=map(int,input().split())
	if a>b: x+=1
	elif a<b: y+=1
print(x,y)