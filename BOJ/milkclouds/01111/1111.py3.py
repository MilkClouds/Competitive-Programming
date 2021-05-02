n=int(input())
if n==1:
    print('A')
    exit()
a=list(map(int,input().split()))
if n==2:
    if a[0]==a[1]:
        print(a[0])
    else:
        print('A')
    exit()

if a[1]==a[0]:
    if len(set(a))==1:
        print(a[0])
    else:
        print('B')
    exit()

A=(a[2]-a[1])//(a[1]-a[0])
B=a[1]-a[0]*A
for i in range(1,n):
    if a[i]!=a[i-1]*A+B:
        print('B')
        exit()
print(a[-1]*A+B)