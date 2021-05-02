import sys
input=sys.stdin.readline

index=0
while 1:
    index+=1
    r=input()
    a,op,b=r.split()
    if op=='E': exit()
    print("Case %d: %s"%(index,str(eval(r)).lower()))