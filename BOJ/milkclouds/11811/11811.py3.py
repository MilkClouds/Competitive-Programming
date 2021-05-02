import sys;input=sys.stdin.readline
n=int(input())
m=[]
for i in range(n):
    m.append(list(map(int,input().split())))
a=[0]*n
for i in range(n):
    for j in range(n):
        a[i]|=m[i][j]
        a[i]|=m[j][i]
print(*a)