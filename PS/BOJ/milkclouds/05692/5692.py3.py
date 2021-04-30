import sys
input=sys.stdin.readline
fact=[1,2,6,24,120]

i=(input().rstrip())
while i!='0':
	r=0
	for ind,d in enumerate(i[::-1]):
		r+=fact[ind]*int(d)
	print(r)
	i=(input().rstrip())
	