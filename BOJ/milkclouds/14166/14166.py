from heapq import *
import sys
input = sys.stdin.readline
N, K = map(int, input().split())
# N, K <= 1e5, M <= 10
class Partition:
    def __init__(self, S, pos, cnt):
        self.S = S
        self.pos = pos
        self.cnt = cnt
    def nxt(self):
        ret = []
        if self.cnt + 1 < len(A[self.pos]):
            ret.append(Partition(self.S + A[self.pos][self.cnt + 1], self.pos, self.cnt + 1))
        if self.cnt:
            if self.pos + 1 < N and len(A[self.pos + 1]) > 1:
                ret.append(Partition(self.S + A[self.pos + 1][1], self.pos + 1, 1))
                if self.cnt == 1:
                    ret.append(Partition(self.S + A[self.pos + 1][1] - A[self.pos][self.cnt], self.pos + 1, 1))
        return ret
    def __gt__(self, oth):
        return self.S > oth.S
    def __repr__(self):
        return "%d, %d, %d" % (self.S, self.pos, self.cnt)
A = []
for i in range(N):
    B = [*map(int, input().split())][1:]
    B.sort()
    for j in range(len(B) - 2, -1, -1):
        B[j + 1] -= B[j]
    A.append(B)
A.sort(key = lambda i: i[1] if len(i) > 1 else 10 ** 9)
pq = []
heappush(pq, Partition(sum(A[i][0] for i in range(N)), 0, 0))
ans = 0
for i in range(K):
    u = heappop(pq)
    ans += u.S
    for v in u.nxt():
        heappush(pq, v)
print(ans)