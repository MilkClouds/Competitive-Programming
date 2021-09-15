from math import *
import sys
FPM = 5280
IPF = 12
SPH = 3600
n = 0
for line in sys.stdin:
    n += 1
    diam, nrev, dur = map(float, line.split())
    if nrev == 0: break
    dist = diam * pi * nrev
    m = dist / (FPM * IPF)
    print("Trip #%d: %.2f %.2f" % (n, m, m / (dur / SPH)))
