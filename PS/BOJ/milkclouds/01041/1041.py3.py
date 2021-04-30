n=int(input())
dice=list(map(int,input().split()))

zz=0;l=[]
for a,b in ((0,5),(1,4),(2,3)):
	l.append(min(dice[a],dice[b]))
l.sort()
	
x,y,z=l[0],l[0]+l[1],sum(l)

dice.sort()
if n==1: print(sum(dice[:5]))
else:
	r=0
	r+=y*(8*n-12)
	r+=z*4
	r+=x*((n-2)*(5*n-6))
	print(r)