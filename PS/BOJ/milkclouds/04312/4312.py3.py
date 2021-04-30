while 1:
    N = int(input())
    if N==0:break
    N-=1
    if N==0:
        print("{ }")
        continue
    ans = []
    for i in range(65):
        if N&(1<<i):
            ans.append(3**i)
    print("{",', '.join(map(str,ans)),"}")