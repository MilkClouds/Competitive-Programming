d={}
for i in range(12*60):
    a=i//60*30
    b=(i%60)*6
    d[a-b]=d[b-a]=1

import sys
for i in map(int,sys.stdin):
    print("Y" if d.get(i) else "N")