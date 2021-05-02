import sys
l = -11
for i in sys.stdin.readlines():
    i = float(i)
    if l == -11:
        l = i
        continue
    if i == 999:
        break
    print("%.2f" % (i - l))
    l = i