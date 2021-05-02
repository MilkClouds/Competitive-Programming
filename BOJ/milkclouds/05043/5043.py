N, b = map(int, input().split())
print('yes' if N <= (1 << b + 1) - 1 else 'no')
