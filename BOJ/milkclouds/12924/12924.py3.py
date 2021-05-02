A, B = map(int, input().split())

chk = [0]*10**7

for i in range(A, B + 1):
    i = str(i)
    S = set()
    for j in range(1,len(i)):
        S.add(int(i[j:]+i[:j]))
    for t in S:
        if t > int(i):
            chk[t] += 1

ans = 0
for i in range(A, B + 1):
    ans += chk[i]
print(ans)