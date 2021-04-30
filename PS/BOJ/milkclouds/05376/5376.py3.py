from fractions import *
f=Fraction
for _ in range(int(input())):
    s=input()
    ret=f(0)
    if '(' in s:
        ret+=f(s[:s.index('(')])
        l=len(s)-s.index('(')-2
        ret+=f(s[s.index('(')+1:-1])/f(int('9'*l)*10**(s.index('(')-s.index('.')-1))
    else:
        ret+=f(s)
    print(ret)