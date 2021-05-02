d={}
for _ in range(int(input())):
    t=input()[0]
    d[t]=d.get(t,0)+1
flag=0
for i in sorted(d):
    if d[i]>4:
        print(i,end='')
        flag=1
flag or print("PREDAJA")