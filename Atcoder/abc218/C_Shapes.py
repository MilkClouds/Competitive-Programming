import numpy as np
from numpy.core.fromnumeric import shape

N = int(input())
S = []
T = []
for i in range(N):
    S.append(np.array([*input()]))
for i in range(N):
    T.append(np.array([*input()]))
    
S = np.array(S)
T = np.array(T)

def tr(S):
    a = b = 0
    A = np.zeros([N, N], dtype = np.bool8)
    for i in range(N):
        for j in range(N):
            if S[i][j] == '#':
                a = max(a, i)
                b = max(b, j)
    for i in range(N):
        for j in range(N):
            if S[i][j] == '#':
                A[i + (N - a - 1)][j + (N - b - 1)] = 1
    return A

def same(A, B):
    return (tr(A) == tr(B)).all()

if same(np.rot90(S, 1), T) or same(np.rot90(S, 3), T) or same(np.rot90(S, 2), T) or same(np.rot90(S, 4), T):
    print('Yes')
else:
    print('No')