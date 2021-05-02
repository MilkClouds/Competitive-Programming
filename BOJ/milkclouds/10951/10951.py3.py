import sys
input=sys.stdin.readline

inp=input()
while inp:
    print(sum(map(int,inp.split(' '))))
    inp=input()