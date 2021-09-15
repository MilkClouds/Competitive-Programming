N = int(input())
T = int(N * 1.08)
if T < 206:
    print("Yay!")
elif T > 206:
    print(":(")
else:
    print("so-so")