n, k = map(int, input().split())
arr = list(map(int, input().split()))
answer = -1
for i in range(n):
    sum = 0
    cnt = 0
    sqsum = 0
    for j in range(i, n):
        sum += arr[j]
        sqsum += arr[j] * arr[j]
        cnt += 1
        if cnt >= k:
            m = (sum) / cnt
            div = (sqsum * cnt - sum ** 2) / (cnt ** 2)
            if answer == -1 or div < answer:
                answer = div
print(answer ** 0.5)