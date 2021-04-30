n=int(input())
def conv(n):
    return n+sum(map(int,str(n)))
for i in range(n-10**6,n):
    if i>0 and conv(i)==n:
        print(i)
        exit()
print(0)