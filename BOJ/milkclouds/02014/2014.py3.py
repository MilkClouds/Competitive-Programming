import heapq
k, n = map(int, input().split())
p = [*map(int, input().split())]
q = []
x = 1
m = 2 ** 31
while n:
    for _ in p:
        y = x * _
        if y < m:
            heapq.heappush(q, y)
        if not x % _:
            break
    x = heapq.heappop(q)
    n -= 1
print(x)
