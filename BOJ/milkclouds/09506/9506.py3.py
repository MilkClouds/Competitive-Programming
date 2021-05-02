import sys
input=sys.stdin.readline

while 1:
	i=int(input())
	if i<0: break
	d=[1]
	for e in range(2,i//2+1):
		if i%e==0: d.append(e)
	if sum(d)==i:
		print('%d = '%i+' + '.join(map(str,d)))
	else: print('%d is NOT perfect.'%i)