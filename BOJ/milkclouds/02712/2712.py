N = int(input())
for _ in range(N):
    a, b = input().split()
    a = float(a)
    if b == 'kg':
        print("%.04f lb"%(a * 2.2046))
    elif b == 'l':
        print("%.04f g"%(a * 0.2642))
    elif b == 'lb':
        print("%.04f kg"%(a * 0.4536))
    elif b == 'g':
        print("%.04f l"%(a * 3.7854))