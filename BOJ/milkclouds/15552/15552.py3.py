import sys
input = sys.stdin.readline

N=int(input().rstrip())
for i in range(N):
    print(sum(map(int,input().split(' '))))
