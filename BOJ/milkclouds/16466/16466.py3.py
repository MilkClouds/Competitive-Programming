import sys
input=sys.stdin.readline
n=int(input())
m=1
for i in sorted(map(int,input().split())):
	if m==i:m+=1
	else:break
print(m)