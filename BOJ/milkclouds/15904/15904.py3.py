cur=0
for i in input():
    if "UCPC"[cur]==i:
        cur+=1
    if cur==4:
        print("I love UCPC")
        exit()
print("I hate UCPC")