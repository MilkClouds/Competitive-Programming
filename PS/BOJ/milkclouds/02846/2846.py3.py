n=int(input())

ret=0
last=0
start=-1
for i in map(int,input().split()):
    if not ~start: start=i;last=i
    if last<i:
        ret=max(ret,i-start)
    else:
        start=i
    last=i

print(ret)