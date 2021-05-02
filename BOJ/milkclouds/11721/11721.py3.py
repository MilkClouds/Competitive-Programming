n=input()
# n='OneTwoThreeFourFiveSixSevenEightNineTen'
for i,a in enumerate(n):
    if i!=0 and (i)%10==0: print('')
    print(a,end='')
