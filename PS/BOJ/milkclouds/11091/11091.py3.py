import sys
input=sys.stdin.readline

for _ in range(int(input())):
	s=input().rstrip().lower()
	alpha=set(map(chr,range(97,97+26)))
	for i in s:
		if i in alpha:
			alpha.discard(i)
	if alpha:
		print('missing',''.join(sorted(alpha)))
	else:
		print('pangram')