import sys
table={"%":"%25"," " :"%20","!":"%21","$":"%24","(":"%28",")":'%29','*':'%2a'}
for line in sys.stdin:
    if line=='#\n':break
    for i,j in table.items():
        line=line.replace(i,j)
    print(line.rstrip())