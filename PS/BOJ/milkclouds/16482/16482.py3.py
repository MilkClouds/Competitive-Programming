from decimal import Decimal as d
a,b,c=map(d,input().split())
x,y=map(d,input().split())
t=x/(c-x)*y/(a-y)
print(b/(t+1))