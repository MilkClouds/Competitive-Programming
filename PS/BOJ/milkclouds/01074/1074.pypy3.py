N,r,c=map(int,input().split())
idx=0
def f(x,y,n):
    global idx
    if not (x<=r<x+n and y<=c<y+n):
        idx+=n*n
        return
    if(n==1):
        if (x,y)==(r,c):
            print(idx)
            exit()
        idx+=1
        return
    n//=2
    f(x,y,n)
    f(x,y+n,n)
    f(x+n,y,n)
    f(x+n,y+n,n)

f(0,0,1<<N)

print(table[r][c])