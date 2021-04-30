t=list(filter(lambda x:x&1,[int(input()) for i in range(7)]))
if t:
    print(sum(t),min(t),sep='\n')
else: print(-1)
