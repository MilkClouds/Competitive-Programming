N,X=[int(i) for i in input().split(' ')]
A=[int(i) for i in input().split(' ')]
r=[]
for i in A:
    if i<X: r.append(str(i))
print(' '.join(r))