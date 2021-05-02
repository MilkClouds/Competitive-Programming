import math,sys;input=sys.stdin.readline
for _ in range(int(input())):
    t=list(map(int,input().split()))
    ret=0
    for i in range(len(t)):
        for j in range(len(t)):
            if i==j:continue
            ret=max(ret,math.gcd(t[i],t[j]))
    print(ret)