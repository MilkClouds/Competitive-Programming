f = open('../../../in.txt', 'w')
print = lambda *x: f.write(' '.join(map(str, x)) + '\n')

from random import *
N = Q = 5 * 10 ** 5

A = [randint(1, 10 ** 5) for i in range(N)]
print(N, Q)
print(*A)

for i in range(Q // 2):
    print(randint(1, 2), 1, N)
for i in range(Q // 2):
    print(3, randint(1, N))

f.close()
