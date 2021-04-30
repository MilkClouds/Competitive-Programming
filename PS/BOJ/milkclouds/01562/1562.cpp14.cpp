#include <iostream>
using namespace std;
using ll=long long;
const ll MOD=1e9;
/*
dp[i][j][bitmask]=length i, last number j, visited bitmask
*/
int N;
ll memo[105][10][1<<10],ans;

ll dp(int i,int j,int bit){
    if(~memo[i][j][bit])return memo[i][j][bit];
    if(i==N){
        if(bit==(1<<10)-1)return 1;
        return 0;
    }
    long long ans=0;
    if(j<9)
        ans+=dp(i+1,j+1,bit|(1<<j+1));
    if(j>0)
        ans+=dp(i+1,j-1,bit|(1<<j-1));
    return memo[i][j][bit]=ans%MOD;
}

int main() 
{
    cin>>N;
    fill(memo[0][0],memo[N+1][11],-1);
    for(int i=1;i<10;i++)
        ans+=dp(1,i,1<<i);
    cout<<ans%MOD;
    return 0;
}