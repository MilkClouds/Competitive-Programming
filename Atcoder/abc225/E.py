import sys
input = sys.stdin.readline
N = int(input())
class grad:
    def __init__(self, x, y) -> None:
        self.x = x
        self.y = y
    def __lt__(self, other) -> bool:
        return self.y * other.x < self.x * other.y
    def __le__(self, other) -> bool:
        return self.y * other.x <= self.x * other.y
A = []
for i in range(N):
    x, y = map(int, input().split())
    A.append((grad(x - 1, y), x, y))
A.sort()
cnt = 0
pre = [5, 0]
for _, x, y in A:
    if grad(x, y - 1) >= grad(pre[0] - 1, pre[1]):
        cnt += 1
        pre = [x, y]
print(cnt)