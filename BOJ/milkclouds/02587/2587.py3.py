t=list(map(int,[input() for i in range(5)]))
t.sort()
print(sum(t)//len(t))
print(t[2])
