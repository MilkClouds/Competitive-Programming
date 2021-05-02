import sys
input=lambda:sys.stdin.readline().rstrip()
n=int(input())

bases=input()
def cmp(a,b):
    return int(a)<int(b) if a.isdigit() and b.isdigit() else ord(a[0])<ord(b[0])
def cmp2(a,b):
    return int(a)>int(b) if a.isdigit() and b.isdigit() else ord(a[0])>ord(b[0])
for _ in range(n):
    target=list(input())
    base=list(bases)
    say=0
    while target and base:
        a=''
        b=''
        while target and target[0].isdigit():
            a+=target[0]
            target.pop(0)
        while base and base[0].isdigit():
            b+=base[0]
            base.pop(0)
        if not a:
            a=target[0]
            target.pop(0)
        if not b:
            b=base[0]
            base.pop(0)
        if cmp(a,b):
            print('-')
            say=1
            break
        if cmp2(a,b):
            print('+')
            say=1
            break
    if not say:
        if not (target or base):
            print('+')
        else:
            print('+' if target else '-')