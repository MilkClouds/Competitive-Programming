n=int(input())

if n%10:
    print(-1)
    exit()

print(n//300,n%300//60,n%300%60//10)