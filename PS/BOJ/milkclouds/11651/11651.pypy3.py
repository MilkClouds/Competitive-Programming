import sys
input=sys.stdin.readline
d=[tuple(map(int,input().split())) for i in range(int(input()))]
d.sort(key=lambda x:x[0])
d.sort(key=lambda x:x[1])
for a,b in d: print(a,b)