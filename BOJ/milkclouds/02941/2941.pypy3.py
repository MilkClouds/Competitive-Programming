r="""č c=
ć c-
ñ d-
š s=
1 lj
1 nj
ž z="""

t=[i.split(' ')[1] for i in r.split('\n')]

S=input()
S=S.replace('dz=','&')
n=len(S)
for i in t:
    n-=S.count(i)
print(n)