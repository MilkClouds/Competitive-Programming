N,L=[int(i) for i in input().split(' ')]

for i in range(L,102):
    if (N-(i-1)*i//2)%i==0: break

if i>100: print(-1)
elif (N-(i-1)*i//2)//i<0: print(-1)
else: print(*[(N-(i-1)*i//2)//i+a for a in range(i)])