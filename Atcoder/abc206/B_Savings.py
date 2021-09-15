N = int(input())
for i in range(1, 1234567):
    if i * (i + 1) // 2 >= N:
        break
print(i)