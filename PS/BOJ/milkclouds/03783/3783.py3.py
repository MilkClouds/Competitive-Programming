import sys
from decimal import *
getcontext().prec=1000
input()
pp=print
print = sys.stdout.write
for n in map(Decimal,sys.stdin):
    t=str(round(n**(Decimal(1)/3),500))
    cnt=0
    dot=0
    for i in t:
        if dot==1:
            cnt+=1
        if cnt>10: break
        if i=='.':
            dot=1
        print(i)
    if not dot:
        print('.0000000000')
    elif cnt<10:
        print('0'*(10-cnt))
    print('\n')