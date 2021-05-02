def lca(u,v):
    if u<v:u,v=v,u
    while u!=v:
        u//=2
        if u<v:u,v=v,u
    return u

import sys
input=sys.stdin.readline

for _ in range(int(input())):
    u,v=map(int,input().split())
    print(lca(u,v)*10)