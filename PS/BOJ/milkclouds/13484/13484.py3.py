import sys
input=sys.stdin.readline

x=int(input())
n=int(input())
print(x*n+x-sum(int(input()) for i in range(n)))