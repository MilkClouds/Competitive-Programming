N=int(input())
ans=0
save=[0]*1000002
for h in map(int,input().split()):
    save[h]+=1
    if save[h+1]:
        save[h+1]-=1
    else:
        ans+=1
print(ans)