a,b,c=map(int,input().split())
x,y,z=map(int,input().split())
print(x-a+(1 if y>b or (y==b and z>=c) else 0)-1)
print(x-a+1)
print(x-a)