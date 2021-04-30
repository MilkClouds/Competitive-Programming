import sys
for a,b in map(lambda x:map(int,x.split()),sys.stdin):
	print('%.2f'%(a/b))