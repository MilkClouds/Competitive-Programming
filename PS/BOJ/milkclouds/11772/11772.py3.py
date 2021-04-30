from math import pow
r=0
for _ in range(int(input())):
    t=input()
    r+=pow(int(t[:-1]),int(t[-1]))
print(int(r))