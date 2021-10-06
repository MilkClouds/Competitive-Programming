N = input()
from itertools import permutations
ans = 0
for S in permutations(N):
    for i in range(1, len(N)):
        a = ''.join(S[:i])
        b = ''.join(S[i:])
        if a.startswith('0') or b.startswith('0'): continue
        ans = max(ans, int(a) * int(b))
print(ans)