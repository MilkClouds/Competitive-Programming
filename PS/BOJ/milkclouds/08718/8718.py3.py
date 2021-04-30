x,k=map(float,input().split())
x*=1000
k*=1000
t = [7*k, 3.5*k, 3.5*k/2]
for i in t:
    if x >= i:
        print(int(i))
        exit()
print(0)