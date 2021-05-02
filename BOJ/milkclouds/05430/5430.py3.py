from collections import deque
import sys
input=sys.stdin.readline
for _ in range(int(input())):
	func=input()[:-1];n=int(input())
	a=deque(eval(input()))
	rev=0;qlen=n;err=0
	for i in func:
		if i=='R':rev=0 if rev else 1
		else:
			if not qlen: err=1;break
			qlen-=1
			if rev: a.pop()
			else: a.popleft()
	if err: print('error')
	else:
		if rev:a.reverse()
		print('[',','.join(map(str,a)),']',sep='')