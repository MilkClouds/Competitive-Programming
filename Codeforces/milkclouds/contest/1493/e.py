N = int(input())
L = input(); l = int(L, 2)
R = input(); r = int(R, 2)
if L[0] != R[0]:
    print('1' * N)
    exit()
print(R if R[-1] == '1' or r - l < 2 else R[:-1] + '1')
