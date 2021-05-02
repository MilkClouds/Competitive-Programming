n=int(input())
a=input()
for i in range(2*n-1):
    if a[i]==a[i+1]:
        print("No")
        break
else:
    print("Yes")