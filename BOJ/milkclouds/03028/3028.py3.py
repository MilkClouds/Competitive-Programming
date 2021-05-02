a, b, c = 1, 0, 0
for i in input():
    if i == 'A':
        a, b = b, a
    if i == 'B':
        c, b = b, c
    if i == 'C':
        a, c = c, a

if a == 1:
    print(1)
if b == 1:
    print(2)
if c == 1:
    print(3)