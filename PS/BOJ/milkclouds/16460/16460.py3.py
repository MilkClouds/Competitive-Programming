import sys
input=sys.stdin.readline
a,b,c=input().split();b='FM' if b=='MF' else b;c=int(c);rr=[]
for _ in range(int(input())):
	x,y,z=input().split();z=int(z)
	if (b=='FM' or y==b) and z<=c:rr.append(x)
if not rr:print('No one yet')
else:print(*sorted(rr),sep='\n')