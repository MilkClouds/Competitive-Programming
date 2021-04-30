a,b=map(int,input().split())

if a>b:a,b=b,a

if a<0:c=(-a)*(-a+1)//2
else:c=a*(a+1)//2

if b<0:d=(-b)*(-b+1)//2
else:d=b*(b+1)//2

if 0<=a<=b: print(d-c+a)
elif a<=0<=b: print(d-c)
elif a<=b<=0: print(-(c-d-b))