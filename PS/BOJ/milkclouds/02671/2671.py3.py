import re
r=re.compile(r'((100+1+)|(01))+')

i=input()
if re.fullmatch(r,i): print('SUBMARINE')
else: print('NOISE')