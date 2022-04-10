import sys
from collections import deque
input = sys.stdin.readline
A = deque()
for _ in range(int(input())):
    q, *params = map(int, input().split())
    if q == 1:
        x, c = params
        A.append((x, c))
    else:
        c = params[0]
        ans = 0
        while c:
            x, c0 = A.popleft()
            c1 = min(c0, c)
            c -= c1; c0 -= c1
            ans += c1 * x
            if c0:
                A.appendleft((x, c0))
        print(ans)