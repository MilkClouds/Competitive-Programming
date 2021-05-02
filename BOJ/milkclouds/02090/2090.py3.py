from fractions import Fraction
input()
r=0
for i in map(int,input().split()):
	r+=1/Fraction(i)
print(1/r if int(1/r)!=(1/r) else "%d/1"%(1/r))
