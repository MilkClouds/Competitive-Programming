def f(x):
    a, b, c = map(int, x.split(':'))
    return a * 3600 + b * 60 + c

print(abs(f(input()) - f(input()) - 3600 * 24) % (3600 * 24))
