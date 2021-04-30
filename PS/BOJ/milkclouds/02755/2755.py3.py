
dic={'A+':4.3,'A0':4,'A-':3.7,'B+':3.3,'B0':3,'B-':2.7,'C+':2.3,'C0':2, 'C-':1.7, 'D+':1.3, 'D0':1, 'D-':0.7, 'F':0}
n=int(input())
sc=0;rate=0
for i in range(n):
 a,b,c=input().split()
 b=int(b)
 sc+=b
 rate+=b*dic[c]
def t(a):
 if 100*a-int(100*a)>=0.5:
  return (int(100*a)+1)/100
 return a
print('%.2f'%(t(rate/sc)))
