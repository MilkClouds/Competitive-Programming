for i in range(int(input())):
    n,m=map(int,input().split())
    if n<0 or m<0 or m>n:print(0)
    else:print(m*(n-m)+1)