a,b=map(int,input().split())
t=[a+b>>1,a-b>>1]
t.sort(reverse=1)
if t[1]<0:print(-1)
elif (a+b)%2 !=0 or (a-b)%2!=0:print(-1)
else: print(*t)