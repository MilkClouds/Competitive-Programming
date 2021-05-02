def factor(n):
	ret=[];ab=n
	for i in range(2,int(n**.5)+1):
		while n%i==0:
			n//=i
			ret.append(i)
			if memo[n]:
				ret.extend(memo[n])
				n=1
				break
	if n!=1: ret.append(n)
	return ret

n=int(input())
d={};memo=[[],[]]
for i in range(2,n+1):
	f=factor(i)
	memo.append(f)
	for e in f:
		d[e]=d.get(e,0)+1

def mul(t):
	r=1
	for i in t: r*=i
	return r
#n!+n!*n!/(x-n!)
print(mul(map(lambda x:2*x+1,d.values())))



