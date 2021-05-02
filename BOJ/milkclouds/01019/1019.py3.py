N=int(input())

index=1; X = N; y=0
result=[0]*10
while X:
    X, mod = divmod(X, 10)
    for j in range(mod): result[j]+=(X+1)*index
    result[mod]+=X*index+y+1
    for j in range(mod+1,10): result[j]+=X*index
    y+=mod*index
    index*=10
result[0]-=(index-1)//9
print(*result)