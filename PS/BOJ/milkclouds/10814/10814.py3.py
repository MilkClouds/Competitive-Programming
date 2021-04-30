N=int(input())
pp=[]
for i in range(N):
    a,b=input().split(' ')
    pp.append((int(a),b))
pp.sort(key=lambda x:x[0])

for i in pp:
    a,b=i
    print(a,b)
