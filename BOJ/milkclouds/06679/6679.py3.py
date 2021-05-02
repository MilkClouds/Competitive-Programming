def f(x,y):
 r=0
 while x:r+=x%y;x//=y
 return r
for i in range(2992,9930):
 if f(i,10)==f(i,12)==f(i,16):print(i)