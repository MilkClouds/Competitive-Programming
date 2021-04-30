def t(a):
    return a if (a>40) else 40
print(sum([t(int(input())) for i in range(5)])//5)