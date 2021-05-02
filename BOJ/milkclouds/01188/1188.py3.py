gcd=lambda a,b:gcd(b,a%b) if b else a
n,m=map(int,input().split())
print(m-gcd(n,m))