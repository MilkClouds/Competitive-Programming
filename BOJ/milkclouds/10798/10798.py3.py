t=[input()+' '*15 for i in range(5)]
print(''.join([''.join(i).replace(' ','') for i in zip(*t)]))