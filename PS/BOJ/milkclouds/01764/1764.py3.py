n,m=map(int,input().split())
a=set([input()for i in range(n)])
b=set([input()for i in range(m)])
c=a&b
print(len(c))
print(*sorted(c),sep='\n')