a,b=input(),input()
a=''.join(filter(lambda x:x>'9',a))
print(1 if a.find(b)!=-1 else 0)