import sys
input=sys.stdin.readline

m=int(input())
n=list(map(int,input().split()))

print(sum(n)-max(n))