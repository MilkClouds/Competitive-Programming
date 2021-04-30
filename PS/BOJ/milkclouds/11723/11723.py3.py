import sys
input=sys.stdin.readline

N=int(input())

S=0

for i in range(N):
    r=input()
    if r=='empty\n': S=0
    elif r=='all\n': S=(1<<20)-1
    else:
        cmd,var=r.split()
        var=int(var)-1
        if cmd=='add':
            S|=1<<var
        elif cmd=='remove':
            S&=~(1<<var)
        elif cmd=='check':
            print(1 if S&(1<<var) else 0)
        elif cmd=='toggle':
            S^=1<<var
    # print(bin(S))