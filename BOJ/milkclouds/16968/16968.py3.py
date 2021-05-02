b=[*map(str,range(10))]
a=[chr(i) for i in range(97,97+26)]

t = input()
def f(t,s='',c=0):
    if c == len(t):
        return 1
    ans = 0
    if t[c]=='c':
        for i in a:
            if s and s[-1] == i: continue
            ans += f(t, s+i, c+1)
    else:
        for i in b:
            if s and s[-1] == i: continue
            ans += f(t, s+i, c+1)
    return ans

print(f(t))