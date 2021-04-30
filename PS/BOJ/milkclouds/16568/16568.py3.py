n,a,b=map(int,input().split())
m=1e12
a+=1;b+=1
for i in range(n//a+1):
    r=n-i*a
    m=min(m,i+r//b+r%b)
print(m)
