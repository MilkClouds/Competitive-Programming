h,v=map(float,input().split())
a=(h*h+v*v)**.5
b=(a-h)*h/v
c=(h*h+b*b)**.5
d=h/c
e=(v-b)*d
print('%.2f %.2f'%(c/2,e))