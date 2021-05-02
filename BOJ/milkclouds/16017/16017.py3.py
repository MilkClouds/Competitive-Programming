x=[int(input())for i in range(4)]

if x[0]>=8 and x[3]>=8 and x[2]==x[1]:
    print('ignore')
else:
    print('answer')