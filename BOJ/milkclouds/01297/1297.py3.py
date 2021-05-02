a,b,c=map(int,input().split())
t=(a*a/(b*b+c*c))**0.5
print('%d %d'%(b*t,c*t))