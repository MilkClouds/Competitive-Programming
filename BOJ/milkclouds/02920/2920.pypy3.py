A=[int(i) for i in input().split(' ')]

if A==list(range(1,9)): print('ascending')
elif A==list(range(8,0,-1)): print('descending')
else: print('mixed')