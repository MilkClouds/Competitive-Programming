import sys,math
input=sys.stdin.readline
for _ in range(int(input())):
	n=int(input())
	ret=0
	for _ in range(n):
		x,y=map(int,input().split())
		r=(x*x+y*y)**.5
		if r>200:continue
		if r<=20:
			ret+=10
			continue
		ret+=11-math.ceil(r/20)
	print(ret)