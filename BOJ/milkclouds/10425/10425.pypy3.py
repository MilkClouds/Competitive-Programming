d=[0,1]
for n in range(2,100000+1):
	d.append(d[n-1]+d[n-2])
dic={}
for idx,i in enumerate(d):
	dic[i]=idx
import sys
input()
for i in map(int,sys.stdin):
	print(dic[i])
