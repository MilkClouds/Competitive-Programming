import sys
input=sys.stdin.readline


a,b,c=list(map(int,input().split()))

#11
#10
#11
for i in range(1 if c&1 else 0):
	a^=b
print(a)