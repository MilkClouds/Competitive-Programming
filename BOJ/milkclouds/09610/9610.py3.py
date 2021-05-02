import sys
input=sys.stdin.readline

ret=[0]*5
for _ in range(int(input())):
	a,b=map(int,input().split())
	if a>0 and b>0: ret[0]+=1
	elif a<0 and b>0: ret[1]+=1
	elif a<0 and b<0: ret[2]+=1
	elif a>0 and b<0: ret[3]+=1
	else: ret[4]+=1

for i in range(4):
	print('Q%d: %d'%(i+1,ret[i]))
print('AXIS: %d'%ret[4])