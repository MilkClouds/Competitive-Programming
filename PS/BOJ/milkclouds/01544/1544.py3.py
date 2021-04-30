input()
import sys
from collections import deque as q
#sys.stdin=iter('12 31'.split())
d=[]
for l in sys.stdin:
	l=q(l.rstrip())
	no=0
	for i in d:
		if len(i)==len(l):
			for r in range(len(i)):
				i.rotate(1)
				if i==l:
					no=1
					break
		if no: break
	if not no:d.append(l)
print(len(d))