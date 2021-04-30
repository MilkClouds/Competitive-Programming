import sys
input=sys.stdin.readline

bo=('a','e','o','i','u')
while 1:
	t=input().lower()
	if t=='#\n': exit()
	print(sum([t.count(i) for i in bo]))