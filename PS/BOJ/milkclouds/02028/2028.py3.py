for _ in range(int(input())):
    N=int(input())
    a=str(N)
    t=str(N**2)
    print("YES" if t[len(t)-len(a):]==a else "NO")