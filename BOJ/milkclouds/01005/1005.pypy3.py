T=int(input())

for i in range(T):
    N,M=[int(i) for i in input().split(' ')]
    cost=[int(i) for i in input().split(' ')]
    roads={}
    degree=[0 for i in range(N)]
    for i in range(M):
        a,b=[int(i)-1 for i in input().split(' ')]
        roads[a]=roads.get(a,[])+[b]
        degree[b]+=1
    must=int(input())-1
    queue=[]
    for i,data in enumerate(degree):
        if data==0: queue.append(i)
    buildTime=cost.copy()
    temp=[0 for i in range(N)]
    while queue:
        pop=queue.pop(0)
        for i in roads.get(pop,[]):
            temp[i] = max(temp[i], buildTime[pop] + cost[i])
            degree[i]-=1
            if degree[i]==0:
                queue.append(i)
                buildTime[i]=temp[i]

    print(buildTime[must])

