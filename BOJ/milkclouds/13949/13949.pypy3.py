k, n = map(int,input().split())

from collections import deque

Q = deque([(0, 1, k)])
visit = set()
cnt = 0

while cnt < n:
    a, b, c = Q.popleft()
    if a and not (visit & {a,b,c}):
        visit |= {a,b,c}
        cnt += 1
        print(a, b, c)

    for i in ({k*(b+c)-a,b,c},{a,k*(a+c)-b,c},{a,b,k*(a+b)-c}):
        if len(i) < 3:
            continue
        Q.append(i)