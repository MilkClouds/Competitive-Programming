input()
s = input()
print(min(len(s), len(s.replace("LL", "L")) + 1))