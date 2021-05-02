import sys
input=sys.stdin.readline
print(len([*filter(lambda x:x>0,map(int,input().split()))]))