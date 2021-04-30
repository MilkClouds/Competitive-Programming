t=input()
a=t.count(':-)')
b=t.count(':-(')
if (a,b)==(0,0): print("none")
elif a==b: print('unsure')
elif a>b: print('happy')
else: print('sad')