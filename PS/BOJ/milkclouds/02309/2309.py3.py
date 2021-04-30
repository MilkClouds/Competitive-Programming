A=[]
for i in range(9): A.append(int(input()))

A.sort()
s=sum(A)
B=[(i,j) for i in A for j in A if i!=j]
for i in B:
    if s-sum(i)==100:
        for a in A:
            if a not in i:
                print(a)
        exit()