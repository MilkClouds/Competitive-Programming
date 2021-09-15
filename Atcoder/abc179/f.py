MI = lambda: map(int, input().split())

N, Q = MI()
INF = 10 ** 20

class SegTree:
    def __init__(self, N):
        self.N = N
        self.tree = [N] * 4 * N
        self.lazy = [N] * 4 * N
    def query(self, l, r, node, i):
        if r < i or i < l:
            return N
        self.push(l, r, node)
        if l == r:
            return self.tree[node]
        m = l + r >> 1
        return min(self.query(l, m, node * 2, i), self.query(m + 1, r, node * 2 + 1, i))
    def push(self, l, r, node):
        if self.lazy[node] == N:
            return
        self.tree[node] = min(self.tree[node], self.lazy[node])
        if l != r:
            for v in [node * 2, node * 2 + 1]:
                self.lazy[v] = min(self.lazy[v], self.lazy[node])
        self.lazy[node] = N
    def update(self, l, r, node, s, e, x):
        self.push(l, r, node)
        if r < s or e < l:
            return
        if s <= l and r <= e:
            self.lazy[node] = min(self.lazy[node], x)
            return
        m = l + r >> 1
        self.update(l, m, node * 2, s, e, x)
        self.update(m + 1, r, node * 2 + 1, s, e, x)

Xmin = SegTree(N)
Ymin = SegTree(N)
ans = 0

for _ in range(Q):
    i, x = MI()
    if i == 1:
        pos = Ymin.query(2, N - 1, 1, x) - 1
        ans += pos - 1
        Xmin.update(2, N - 1, 1, 2, pos, x)
    else:
        pos = Xmin.query(2, N - 1, 1, x) - 1
        ans += pos - 1
        Ymin.update(2, N - 1, 1, 2, pos, x)

print((N - 2) ** 2 - ans)
