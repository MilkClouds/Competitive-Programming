import sys,re
input=sys.stdin.readline
def g(a,b):
    if a<b: a,b=b,a
    if a%b==0:return b
    return g(a%b,b)
sa=input().rstrip()
while sa:
    e=re.search(r'\((\d+)\)',sa)
    s=sa.replace('(','').replace(')','')
    a,b=s.split('.')
    if not e:
        u=int(a+b)
        d=10**len(b)
    else:
        u=int(a+b+e[1])-int(a+b)
        d=10**len(b+e[1])-10**len(b)
    G=g(u,d)
    print("%s = %d / %d"%(sa,u//G,d//G))
    sa=input().rstrip()