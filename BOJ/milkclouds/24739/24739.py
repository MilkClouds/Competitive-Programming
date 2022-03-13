from fractions import Fraction
r = Fraction(0)
for i in map(int, input()):
    r = r * 3 / Fraction(2) + i
print(int(r), r - int(r)) if int(r) != r else print(r)