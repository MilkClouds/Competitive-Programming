N=int(input())
d={'A':range(90,101),'B':range(80,90),'C':range(70,80),'D':range(60,70),'F':range(0,60)}

for a,b in d.items():
    if N in b: print(a)

