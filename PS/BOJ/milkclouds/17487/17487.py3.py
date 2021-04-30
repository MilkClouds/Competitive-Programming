A = 'QWERTY' + 'ASDFG' + 'ZXCVB'
a = b = c = 0
for i in input():
    if i == ' ':
        c += 1
        continue
    if i.isupper():
        c += 1
    if i.lower() in A.lower():
        a += 1
    else:
        b += 1


while c:
    if a > b:
        b += 1
        c -= 1
    else:
        a += 1
        c -= 1


print(a, b)