n=int(input())
v=2**(n+1)-1
print(v//3+(1 if v%3 else 0))