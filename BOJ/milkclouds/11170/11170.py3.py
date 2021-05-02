def zeros(n):
    if n < 0:
        return 0
    if n < 10:
        return 1

    res = 1;#if 0
    res += n//10
    power = 10
    while power*10 <= n:
        if (n//power)%10 == 0:
            res += ((n//(power*10)) - 1) * power + 1
            res += (n % power)
        else:
            res += (n//(power*10)) * power
        power *= 10
    return res
t = int(input())
for i in range(t):
    a, b = map(int, input().split())
    print(zeros(b) - zeros(a-1))
