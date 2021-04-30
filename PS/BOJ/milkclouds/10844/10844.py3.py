N=int(input())

D=[0,[0]+[1]*9]
for i in range(2,N+1):
    D.append([0]*10)
    for index in range(10):
        if index==0:
            D[i][0] = D[i-1][1]
        elif index==9:
            D[i][9] = D[i-1][8]
        else:
            D[i][index] = D[i-1][index-1]+D[i-1][index+1]

print(sum(D[N])%(10**9))
