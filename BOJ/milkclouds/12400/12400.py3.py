import sys
input=sys.stdin.readline

d=['y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l',
		'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q']
for _ in range(int(input())):
	s=input().rstrip()
	st=''
	for i in s:
		if 'a'<=i<='z':
			st+=d[ord(i)-97]
		else: st+=i
	print('Case #%d: %s'%(_+1,st))