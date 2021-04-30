import sys
write=lambda *x: sys.stdout.write(' '.join(map(str,x))+'\n')

def solve(u,v,n):
    if n==1:
        write(u,v);return
    if n:
        solve(u,6-u-v,n-1)
        solve(u,v,1)
        solve(6-u-v,v,n-1)
n=int(input())
write((1<<n)-1)
if n>20:exit()
solve(1,3,n)