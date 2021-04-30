from fractions import Fraction
f=Fraction;idx=1
while 1:
    N=int(input())
    if N==0:break
    s=f(0)
    for _ in range(N):
        t=input()
        if ',' in t:
            a,b=t.split(',')
            s+=f(a)+f(b)
        else:
            s+=f(t)
    if int(s)==s:
        ret=str(s)
    else:
        if s>1:
            ret=str(int(s))+","+str(s-int(s))
        else:
            ret=str(s)
    print("Test %d: %s"%(idx,ret))
    idx+=1