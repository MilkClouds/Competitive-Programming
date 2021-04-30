import sys
input=sys.stdin.readline

d=[1,3,6,10,15]
for i in range(5,46):
	d.append(d[i-1]+i+1)
p=set()
for i in d:
	for j in d:
		for k in d:
			if i+j+k>1000: continue
			p.add(i+j+k)

for i in range(int(input())):
	num=int(input())
	print(1 if num in p else 0)