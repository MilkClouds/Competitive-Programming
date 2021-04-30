import sys;input=lambda:sys.stdin.readline().rstrip()
for _ in range(int(input())):
    a,b=input().split()
    print("%s & %s are %sanagrams."%(a,b,'' if sorted(a)==sorted(b) else 'NOT '))