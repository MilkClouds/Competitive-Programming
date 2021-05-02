r=input().strip()

j=1
for i in range(len(r)):
    if r[i]==' ' and r[i+1] !=' ':
        j+=1
print(j if (r) else 0)