s,k=map(int,input().split())
p=s//k;q=s%k
result=1
for i in range(k):
 result*=p if i<k-q else p+1
print(result)