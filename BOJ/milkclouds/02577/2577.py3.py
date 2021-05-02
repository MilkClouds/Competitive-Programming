r=1
for i in range(3):
    r*=int(input())

l=[0 for i in range(10)]
for i in str(r):
    l[int(i)]+=1

print('\n'.join(map(str,l)))