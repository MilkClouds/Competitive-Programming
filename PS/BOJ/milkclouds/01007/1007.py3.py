from itertools import combinations as c
def su(i):
    return [sum(e) for e in i]
for _ in range(int(input())):
    coord=[]
    for _ in range(int(input())):
        coord.append(tuple(map(int,input().split(' '))))
    x,y=su(zip(*coord))
    r=[su(zip(*i)) for i in c(coord,len(coord)//2)]
    m=10**10
    for i in r:
        m=min(m,((2*i[0]-x)**2+(2*i[1]-y)**2)**0.5)
    print(m)