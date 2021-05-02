t=input();ret=''
key={}
for i in range(26):
    key[chr(i+65)]=chr((i+13)%26+65)
    key[chr(i+97)]=chr((i+13)%26+97)
for i in t:
    if i.isalpha(): ret+=key[i]
    else: ret+=i

print(ret)
