a,b=input().split()
r=lambda x:int(x[::-1])
print(r(str(sum(map(r,[a,b])))))