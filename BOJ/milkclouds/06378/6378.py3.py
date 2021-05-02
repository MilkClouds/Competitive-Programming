def f(x):
    t=sum(map(int,x))
    return f(str(t)) if t>=10 else t
import sys
for i in sys.stdin:
    i=i.rstrip()
    if i=='0':break
    print(f(i))