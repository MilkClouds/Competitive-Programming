r=[input(),input()]
r.sort()
while r[0]:
    if ''.join(r[1].split(r[0]))==r[1]: break
    r[0],r[1]=''.join(r[1].split(r[0])),r[0]
print(0 if r[0] else 1)