import sys
input=sys.stdin.readline

def t(s):
	if s==1:return True
	if s&1:return False
	return t(s//2)
for _ in range(int(input())):
	print('GoHanGang' if t(int(input())) else 'Gazua')