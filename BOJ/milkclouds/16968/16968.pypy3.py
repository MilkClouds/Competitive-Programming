d={'c':26,'d':10}

t = input()
MOD = 10**9 + 9
ans = 1
for i in range(len(t)):
    if i==0:
        ans *= d[t[i]]
        continue
    if t[i] != t[i-1]:
        ans *= d[t[i]]
    else:
        ans *= d[t[i]]-1
    ans %= MOD

print(ans)