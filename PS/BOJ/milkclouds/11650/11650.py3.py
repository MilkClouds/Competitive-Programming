import sys;input=sys.stdin.readline
A=[]
for i in range(int(input())):
    A.append(list(map(int,input().split())))
A.sort(key=lambda x:x[1])
A.sort(key=lambda x:x[0])
for i in A: print(*i)