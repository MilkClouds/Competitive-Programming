def solution(numbers):
    ans = 0
    for i in range(10):
        if i in numbers:
            continue
        ans += i
    return ans