import sys
input=sys.stdin.readline
input()
a=set(map(int,input().split()))
for i in map(int,input().split()):
	a.discard(i)
print(len(a))
if a:print(*sorted(a))