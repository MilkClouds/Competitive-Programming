def best(a,b):
    up = [0,a[0]]
    down = [0,b[0]]
    for i in range(1,len(a)):
        up.append(max(down[-1],down[-2],up[-2])+a[i])
        down.append(max(up[-2],up[-3],down[-2])+b[i])
    return max(max(up),max(down))
for T in range(int(input())):
    input()
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    print(best(a,b))