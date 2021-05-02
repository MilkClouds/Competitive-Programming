import sys
input=sys.stdin.readline
for i in range(int(input())):
               t=list(map(int,input().split()))
               t.sort(reverse=1)
               print(t[2])