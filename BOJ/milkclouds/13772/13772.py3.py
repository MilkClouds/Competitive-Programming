hole=[1,2,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0]
for _ in range(int(input())):
    print(sum(hole[ord(i)-65] for i in input() if ord(i)>64))