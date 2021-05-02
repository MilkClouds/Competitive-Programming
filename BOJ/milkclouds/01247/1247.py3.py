import sys
input=sys.stdin.readline
def t(x):
	return 0 if not x else ('+' if x>0 else '-')
[print(t(sum(map(int,[input() for _ in range(int(input()))])))) for _ in range(3)]