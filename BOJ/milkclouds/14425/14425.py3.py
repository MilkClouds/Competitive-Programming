import sys
input=sys.stdin.readline

n,m=map(int,input().split());s=set();r=0
for i in range(n):s.add(input())
for i in range(m):r+=1 if s&{input()} else 0
print(r)