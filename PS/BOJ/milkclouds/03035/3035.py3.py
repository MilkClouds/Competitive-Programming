r,c,zr,zc=map(int,input().split())
arr=[input() for _ in range(r)]
for i in range(r*zr):
    for j in range(c*zc):
        print(arr[i//zr][j//zc],end='')
    print('')