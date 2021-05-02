from decimal import Decimal as d
a,b,c=map(int,input().split())
print(1/(d(1)/a+d(1)/b+d(1)/c))