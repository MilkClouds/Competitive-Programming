import sys
r=sys.stdin.read()

d=0;m=[]
for i in range(26):
    e=r.count(chr(i+97))
    if e==d:
        m.append(chr(i+97))
    if e>d:
        d=e;m=[chr(i+97)]
m.sort()
print(*m,sep='')