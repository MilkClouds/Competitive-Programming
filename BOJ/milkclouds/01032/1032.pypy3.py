A=[input() for i in range(int(input()))]
B=[i[0] if len(set(i))==1 else '?' for i in zip(*A)]
print(*B,sep='')