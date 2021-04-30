import sys
input=sys.stdin.readline
def r(t):
	return t[0].upper()+t[1:]
for _ in range(int(input())):
	print(r(input()[:-1]))