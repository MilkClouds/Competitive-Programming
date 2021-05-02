import sys
input=sys.stdin.readline

s=[int(input()) for i in range(int(input()))]
s.sort(reverse=1);[*map(print,s)]