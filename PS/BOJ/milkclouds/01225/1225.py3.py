a,b=input().split()
b=sum(map(int,b))
print(sum([int(i)*b for i in a]))