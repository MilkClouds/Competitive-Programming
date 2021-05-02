import sys
for i in map(str.rstrip,sys.stdin):
    n=int(i)
    s=set()
    for start in range(len(i)):
        newi=i[start:]+i[:start]
        newn=int(newi)
        if newn%n==0:
            s.add(newn//n)
    if set(range(1,1+len(i)))==s:
        print('%s is cyclic'%i)
    else:
        print('%s is not cyclic'%i)