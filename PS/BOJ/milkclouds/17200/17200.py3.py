N = int(input())

S = {}
for k in range(N):
    t = input().split()
    for i in t[1:]:
        if S.get(i):
            S[i].add(k)
        else:
            S[i] = {k}
for i in S:
    for j in S:
        if i == j: continue
        t = S[i] ^ S[j]
        if (S[i] & S[j]) and (t & S[i]) and (t & S[j]):
            print("no")
            exit()

print('yes')