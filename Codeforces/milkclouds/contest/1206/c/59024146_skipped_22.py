n=int(input())
if n%2==0:
    print("NO")
    exit()
print("YES")
t=1
dt=[3,1]
for i in range(n):
    print(t,end=' ')
    t+=dt[i%2]

t=2
dt=[1,3]
for i in range(n):
    print(t,end=' ')
    t+=dt[i%2]