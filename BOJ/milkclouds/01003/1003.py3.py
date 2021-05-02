"""
    int fibonacci(int n) {
    if (n == 0) {
        printf("0");
        return 0;
    } else if (n == 1) {
        printf("1");
        return 1;
    } else {
        return fibonacci(n‐1) + fibonacci(n‐2);
    }
}
"""

T=int(input())
l=[]
for i in range(T):
    l.append(int(input()))

memo=[(1,0),(0,1),(1,1),(1,2)]
def get(n):
    for i in range(len(memo),n+1):
        memo.append([a+b for a,b in zip(memo[i-1],memo[i-2])])
for i in l:
    if len(memo)-1<i:
        get(i)
    print(' '.join(map(str,memo[i])))