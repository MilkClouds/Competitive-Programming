def self(n):
    return sum(map(int,str(n)))+n

gens=[]
for i in range(1,10000):
    gens.append(self(i))
for i in range(1,10000):
    if i not in gens:
        print(i)
