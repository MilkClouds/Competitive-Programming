from math import log,sin
d=[1]
for i in range(1,1000000):
	d.append((d[int(i-i**.5)]+d[int(log(i))]+d[int(i*sin(i)**2)])%1000000)
import sys
for i in map(int,sys.stdin):
	if i<0: break
	print(d[i])