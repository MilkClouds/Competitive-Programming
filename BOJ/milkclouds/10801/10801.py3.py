A=list(map(int,input().split()))
B=list(map(int,input().split()))
winA=winB=0
for i in range(10):
    winA+=A[i]>B[i]
    winB+=B[i]>A[i]
print("A" if winA>winB else ("B" if winB>winA else "D"))