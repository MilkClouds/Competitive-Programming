C=int(input())
for i in range(C):
    A=[int(i) for i in input().split(' ')]
    avg=sum(A[1:])/A[0]
    s=0
    for i in A[1:]:
        if i>avg: s+=1
    print("%.3f%%"%round(s/A[0]*100,3))