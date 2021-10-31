S = input()
SS = set()
from itertools import permutations
for i in permutations(S):
    SS.add(i)
print(len(SS))