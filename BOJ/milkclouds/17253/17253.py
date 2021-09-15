N = int(input())
def f(x):
    if x == 0: return 0
    while x:
        if x % 3 == 2: return 0
        x //= 3
    return 1
print("YES" if f(N) else "NO")