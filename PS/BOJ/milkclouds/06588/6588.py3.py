import sys
input=sys.stdin.readline

p=[0,0,1,1]+[1]*(1000000-3)

p[4::2]=[0]*(10**6//2-1)
p[6::3]=[0]*(10**6//3-1)
for i in range(5,1000000):
	if p[i]==1:
		if i%6 not in (1,5):
			p[i]=0
		else:
			p[i+i::i]=[0]*(10**6//i-1)
#			for a in range(2,i**0.5+1):
#				if i%a==0: 


while 1:
	i=int(input())
	if i==0: break
	for a in range(i,i//2-1,-1):
		if p[a]:
			b=(i-a)
			if p[b]:
				print('%d = %d + %d'%(i,b,a))
				break