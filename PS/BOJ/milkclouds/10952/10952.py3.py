import sys
input=sys.stdin.readline

inp=input()
while inp:
    r=list(map(int,inp.split(' ')))
    if r==[0,0]: break
    print(sum(r))
    inp=input()