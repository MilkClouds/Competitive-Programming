input()
a,b=[list(map(int,input().split())) for i in range(2)]

a.sort()
b.sort(reverse=1)
print(sum([i*j for i,j in zip(a,b)]))