A = {}
B = {}
for i, j in enumerate(input()):
    A[j] = i
B = input()
for i in input():
    if not i.isalpha():
        print(i, end = '')
        continue
    tmp = B[A[i.lower()]]
    if i.isupper():
        tmp = tmp.upper()
    print(tmp, end = '')
