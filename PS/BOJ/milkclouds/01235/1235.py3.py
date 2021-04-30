import sys;input=sys.stdin.readline

n=int(input())
a=[input().rstrip()for _ in range(n)]
for idx in range(len(a[0])):
    s=set()
    for i in range(n):
        s.add(a[i][len(a[0])-idx-1:])
    if len(s)==n:
        print(idx+1)
        exit()
