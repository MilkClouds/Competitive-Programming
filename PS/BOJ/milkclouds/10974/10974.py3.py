n=int(input())
from itertools import permutations as p
import sys
print=sys.stdout.write
for i in p(range(1,n+1),n):
	print(' '.join(map(str,i))+'\n')