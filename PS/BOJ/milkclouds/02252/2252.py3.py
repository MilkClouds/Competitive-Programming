N,M=[int(i) for i in input().split(' ')]
# roads=[[0 for i in range(N)] for i in range(N)]
roads={}
degree=[0 for i in range(N)]
for i in range(M):
    a,b=[int(i)-1 for i in input().split(' ')]
    degree[b]+=1
    # roads[a][b]=1
    roads[a]=roads.get(a,[])+[b]

queue=[]
for i,data in enumerate(degree):
    if data==0: queue.append(i)

ans=[]
while(queue):
    a=queue.pop(0)
    ans.append(a)
    for i in (roads.get(a,[])):
        degree[i]-=1
        if degree[i]==0: queue.append(i)

print(' '.join(map(lambda x:str(x+1),ans)))
