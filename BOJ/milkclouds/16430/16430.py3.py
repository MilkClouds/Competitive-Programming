from fractions import Fraction
p,q=map(Fraction,input().split())
print(str(1-p/q).replace('/',' '))