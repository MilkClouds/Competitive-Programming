i=lambda x:int(x)-1
input()
print(sum([1 for i,j in enumerate(map(i,input().split())) if i!=j]))