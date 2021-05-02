import sys
input()
def round(n,digit):
	r=10**abs(digit)
	if int(str(n)[digit])>=5:
		return (1+n//r)*r
	return n//r*r
try:
	for n in map(int,sys.stdin):
		for i in range(1,len(str(n))):
			n=round(n,-i)
		print(n)
except:
	pass