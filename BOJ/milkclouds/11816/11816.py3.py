t=input()
if t.startswith('0x'): print(int(t,16))
elif t.startswith('0'): print(int(t,8))
else: print(t)