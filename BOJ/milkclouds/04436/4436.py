import sys
for line in sys.stdin:
    n = int(line)
    S = set()
    for k in range(1, 100000):
        S |= set(str(n * k))
        if len(S) == 9: break
    print(k)