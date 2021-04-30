import sys
input=sys.stdin.readline
print=sys.stdout.write
input()
print(' '.join(map(str,sorted(list(map(int,input().split()))+list(map(int,input().split()))))))