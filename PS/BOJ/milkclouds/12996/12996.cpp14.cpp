#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
using namespace std;
using ll=long long;
const int MOD=1e9+7;
ll S,a,b,c, dp[52][52][52][52];

ll solve(int S,int a,int b,int c){
    if(a<0||b<0||c<0)return 0;
    if(S==0)return a==0&&b==0&&c==0;
    ll& ret=dp[S][a][b][c];
    //printf("%d %d %d %d\n",S,a,b,c);
    if(~ret)return ret;
    ret=0;
    rep(i,0,2)rep(j,0,2)rep(k,0,2){
	if(!(i||j||k)) continue;
	ret+=solve(S-1,a-i,b-j,c-k);
	}
    ret%=MOD;
    return ret;
}
int main(){
    cin>>S>>a>>b>>c;
    fill(dp[0][0][0], dp[S+1][a+1][b+1], -1);
    cout<<solve(S,a,b,c);
}