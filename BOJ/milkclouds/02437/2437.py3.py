n=int(input())
s=0
for i in sorted(map(int,input().split())):
    if i>=s+2:
        print(s+1)
        exit()
    s+=i
print(s+1)