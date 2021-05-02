def exp(n, ini, lim):
    cur = ini
    for i in range(n):
        cur*= 2
        if cur > lim: return float('inf')
    return cur

def fac(n, ini, lim):
    cur = ini
    for i in range(n):
        cur*= i+1
        if cur > lim: return float('inf')
    return cur

for TEST in range(int(input())):
    s, *param = input().split()
    N, T, L = map(int, param)
    lim = 100000000*L
    if s == "O(N)": res = T*N
    elif s == "O(N^2)": res = T*N*N
    elif s == "O(N^3)": res = T*N**3
    elif s == "O(2^N)": res = exp(N, T, lim)
    elif s == "O(N!)": res = fac(N, T, lim)
    print("May Pass." if res <= lim else "TLE!")
    