a=sorted([(i,int(input())) for i in range(8)],key=lambda x:x[1],reverse=1)[:5]
print(sum([i[1] for i in a]))
print(*sorted([i[0]+1 for i in a]))