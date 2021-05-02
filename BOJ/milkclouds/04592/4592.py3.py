import sys
def func(v):
    dic=[]
    for i in range(len(v)):
        if i==0 or v[i]!=v[i-1]:
            dic.append(v[i])
    return dic
for line in sys.stdin:
    if line=='0\n':break
    print(*func(list(map(int,line.split()))[1:]),'$')