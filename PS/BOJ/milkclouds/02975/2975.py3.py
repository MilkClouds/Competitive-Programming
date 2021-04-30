while 1:
    a,b,c=input().split()
    a=int(a);c=int(c)
    if (a,b,c)==(0,'W',0):break
    a+=(-1 if b=='W' else 1)*c
    print("Not allowed" if a<-200 else a)