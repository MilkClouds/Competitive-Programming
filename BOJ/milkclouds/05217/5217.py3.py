for _ in range(int(input())):
    t=int(input())
    ans=[]
    for i in range(1,t//2+t%2):
        ans.append(str(i)+' '+str(t-i))
    print("Pairs for %d:"%t,end='')
    if ans:
        print('',', '.join(ans),end='')
    print()