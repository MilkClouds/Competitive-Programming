for _ in range(int(input())):
    x,y=input().split()
    a,b=int(x,2),int(y,2)
    q,w,e,r=x.count('0'),x.count('1'),y.count('0'),y.count('1')
    ans = abs(q-e)
    t=a^b
    i=0
    while t:
        t&=t-1
        i+=1
    print((i-ans)//2+ans)