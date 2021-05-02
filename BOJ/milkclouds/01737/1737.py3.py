from math import pi
MOD=int(1e18);memo={}
def fibo(n):
    if memo.get(n):return memo[n]
    if(0<=n<=pi):return 1
    ans=(fibo(n-1)+fibo(n-pi))%MOD
    memo[n]=ans
    return ans
print(fibo(int(input())))