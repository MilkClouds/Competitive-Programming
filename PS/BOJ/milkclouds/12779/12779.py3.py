a,b=map(int,input().split())
r=0


t=(a+1)**0.5
if t==int(t): start=int(t)
else: start=int(t)+1
t=b**0.5
end=int(t)
r=end-start+1

if r==0: print(0); exit()

def G(a,b):
	if a<b:a,b=b,a
	while a%b!=0:
		a,b=b,a%b
	return b
g=G(b-a,r)
print('%d/%d'%(r//g,(b-a)//g))