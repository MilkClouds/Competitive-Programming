def disc(n):
    r=list(map(int,str(n)))
    if len(r) in (1,2): return 1
    if (r[0]-r[1])==(r[1]-r[2]): return 1
    return 0

N=int(input())
print(sum([disc(i) for i in range(1,N+1)]))
