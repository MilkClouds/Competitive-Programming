def f(i):
    a,b,c = map(int, i.split(':'))
    return a*60*60+b*60+c
def g(i):
    a = i // 3600
    i -= a * 3600
    b = i // 60
    i -= b * 60
    c = i
    return "%02d:%02d:%02d" % (a, b, c)

a = f(input())
b = f(input())

if a < b:
    print(g(b - a))
else:
    print(g(b - a + 60 * 60 * 24))