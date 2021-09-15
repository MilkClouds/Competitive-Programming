A, B, W = map(int, input().split())
W *= 1000

a = W // B + (W % B > 0)
C = A * a
D = B * a

if C <= W <= D:
    print(W // B + (W % B > 0), W // A)
else:
    print("UNSATISFIABLE")
