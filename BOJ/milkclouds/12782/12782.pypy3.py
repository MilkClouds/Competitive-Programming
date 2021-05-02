for _ in range(int(input())):
    x,y=input().split()
    a,b=int(x,2),int(y,2)
    q,e=x.count('0'),y.count('0')
    ans = abs(q-e)
    t=a^b
    i=0
    while t:
        t&=t-1
        i+=1
    print((i-ans)//2+ans)