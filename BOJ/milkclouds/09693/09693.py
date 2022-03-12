import sys
for i, line in enumerate(sys.stdin):
    n = int(line)
    if n == 0:
        break
    ret = 0
    while n:
        ret += n // 5
        n //= 5
    print("Case #%d: %d" % (i + 1, ret))