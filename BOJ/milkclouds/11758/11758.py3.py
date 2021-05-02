a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=list(map(int,input().split()))
t=(b[0]-a[0])*(c[1]-b[1])-(b[1]-a[1])*(c[0]-b[0])
print((t>0)-(t<0))