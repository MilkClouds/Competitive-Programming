n=int(input())
if sum(map(int,str(n)))%3==0 and '0' in str(n):
    print(*sorted(str(n),reverse=1),sep='')
else:
    print(-1)