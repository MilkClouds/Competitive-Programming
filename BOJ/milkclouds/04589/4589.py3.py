print("Gnomes:")
for _ in range(int(input())):
    s=list(map(int,input().split()))
    print("Ordered" if s==sorted(s) or s==sorted(s,reverse=1) else "Unordered")