A = int(input())
B = int(input())
print(str(B // 2) + ("5" if B % 2 else "0") + str(A)) if B > 1 else print("5" + str(A))