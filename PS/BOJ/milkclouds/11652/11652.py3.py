import sys
input=sys.stdin.readline
d={}
for _ in range(int(input())):
    t=int(input())
    d[t]=d.get(t,0)+1

print(max(d.items(),key=lambda x:x[1] * (1 << 63) - x[0])[0])