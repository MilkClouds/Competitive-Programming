x,y,z=map(int,input().split())
f=lambda x:zip(x,x)
def g():
    c={}
    a=[]
    for x, y in f(iter(input().split())):
        c[x] = c.get(x, 0) + int(y)
        None if x in a else a.append(x)
    return [*filter(lambda x:c[x]>19,a)]
a,b,c=[g() for _ in range(3)]
a=[x for x in a if x in b and x in c]
print(len(a), *a)