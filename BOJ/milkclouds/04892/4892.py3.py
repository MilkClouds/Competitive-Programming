idx=0
while 1:
	idx+=1
	n=int(input())
	if not n:break
	print("%d. %s %d"%(idx,"odd" if n&1 else 'even',n//2))