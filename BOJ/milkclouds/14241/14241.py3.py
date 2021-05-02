input()
s=r=0
for i in map(int,input().split()):
    r+=s*i
    s+=i
print(r)