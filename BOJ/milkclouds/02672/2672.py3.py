import sys
from decimal import *
inp='''4
52.7 22.9 27.3 13.3
68.8 57.6 23.2 8.0
20.0 48.0 37.0 23.5
41.5 36.2 27.3 21.4'''.split('\n')

c=-1
def input():
	global c
	c+=1
	return inp[c]
input=sys.stdin.readline
n=int(input())
rect=[]
ys=[]
event=[]
for i in range(n):
	x,y,w,h=map(Decimal,input().split())
	rect.append((x,y,x+w,y+h))
	ys.append(y)
	ys.append(y+h)
	event.append((x,1,i))
	event.append((x+w,-1,i))

ys=list(set(ys))
ys.sort()
event.sort()

ret=0
count=[0]*len(ys)
for i in range(len(event)):
	a,b,c=event[i]
	y1,y2=rect[c][1::2]
	for j in range(len(ys)):
		if y1<=ys[j]<y2:
			count[j]+=b
	cutl=0
	for j in range(len(ys)-1):
		if count[j]>0:
			cutl+=ys[j+1]-ys[j]
	if i+1<len(event):
		ret+=cutl*(event[i+1][0]-a)

if int(ret)==ret:
	print(int(ret))
else: print('%.2f'%ret)