i = 0
while 1:
    a = input()
    b = input()
    i += 1
    if a == 'END': break
    print('Case %d:' % i, 'same' if sorted(a) == sorted(b) else 'different')