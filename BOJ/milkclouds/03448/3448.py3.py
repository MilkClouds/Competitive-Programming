f=lambda n:int(n) if int(n)==n else n
for _ in range(int(input())):
    x=''
    while 1:
        t=input()
        if not t:break
        x+=t
    ans=f(round((100-x.count('#')*100/len(x))*10)/10)
    print("Efficiency ratio is",str(ans)+"%.")
