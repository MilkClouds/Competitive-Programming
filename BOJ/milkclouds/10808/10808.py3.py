n=input()
print(*[n.count(chr(97+i)) for i in range(26)])