from math import *
import sys
def f(n):
	return n*log10(n)-n/log(10)
def ff(n):
	return f(n)-f(1)

n=input().rstrip()
d={'1':'1','2':'2','6':'3','24':'4','120':5}
if d.get(n):
	print(d[n])
	exit()

l=len(n)-1
if l<100:
	r=log10(120)
	idx=5
	while 1:
		idx+=1
		r+=log10(idx)
		if int(r)==l:
			print(idx)
			exit()
start=0
end=230000
while (start+1<end):
	mid=(start+end)//2
	if int(ff(mid))<=l:
		start=mid
	else:
		end=mid
print(start)