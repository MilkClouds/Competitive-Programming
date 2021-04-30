import sys;input=sys.stdin.readline
d=(3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1)

a=input()[:-1]
b=input()[:-1]

l=[]
for i,j in zip(a,b):
	l.append(d[ord(i)-65])
	l.append(d[ord(j)-65])

def func(l):
	ret=[]
	for i,j in enumerate(l[:-1]):
		ret.append((j+l[i+1])%10)
	return ret

while len(l)!=2:
	l=func(l)
print("%02d"%(l[0]*10+l[1]))