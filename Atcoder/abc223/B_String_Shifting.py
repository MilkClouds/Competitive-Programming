S = input()
SS = []
for i in range(len(S)):
    SS.append(S[i:] + S[:i])
SS.sort()
print(SS[0])
print(SS[-1])