a,b,c=sorted([*map(int,input().split())])
if c*c == b*b+a*a:
    print(1)
elif c==b and b==a:
    print(2)
else:
    print(0)
