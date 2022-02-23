A = [[*map(int, input().split())] for _ in range(5)]
R = [0] * 5
C = [0] * 5
P = [0, 0]
cnt = ans = 0
for _ in range(5):
    for x in [*map(int, input().split())]:
        cnt += 1
        for i in range(5):
            if A[i].count(x):
                j = A[i].index(x)
                break
        R[i] += 1
        C[j] += 1
        if i + j == 4:
            P[0] += 1
            ans += (P[0] == 5)
        if i - j == 0:
            P[1] += 1
            ans += (P[1] == 5)
        ans += (R[i] == 5) + (C[j] == 5)
        if ans >= 3:
            print(cnt)
            exit()
        
    
