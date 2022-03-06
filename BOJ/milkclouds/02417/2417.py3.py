def sqrt(x):
    j = 0
    for i in range(64, -1, -1):
        if (j + (1 << i)) ** 2 <= x:
            j += 1 << i
    return j if j * j == x else j + 1
print(sqrt(int(input())))