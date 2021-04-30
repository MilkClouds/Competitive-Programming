p1,p2,p3,x1,x2,x3=map(int,input().split())
for i in range(x1, p1*p2*p3, p1):
    if i%p2==x2 and i%p3==x3:print(i);break
else: print(-1)