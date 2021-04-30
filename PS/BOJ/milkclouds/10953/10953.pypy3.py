import sys
input=sys.stdin.readline
input()
inp=input()
while inp:
    print(sum(map(int,inp.split(','))))
    inp=input()