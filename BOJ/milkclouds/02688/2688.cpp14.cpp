# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<c;a++)
#define rep2(a,b,c) for(ll a=b;a>c;a--)
#define pb push_back
#define x first
#define y second
#define all(x) x.begin(), x.end()
using namespace std;
using ll=long long;
using ti=tuple<ll,ll,ll>;
using pi=pair<ll,ll>;

int T, N;
ll memo[65][10];
ll dp(int N,int last){
	ll& ret = memo[N][last];
	if(ret) return ret;
	rep(i, 0, last + 1) ret += dp(N-1,i);
	return ret;
}
ll solve(int N){
	ll ret = 0;
	rep(i, 0, 10){
		ret += dp(N, i);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> T;
	rep(i,0,10)memo[1][i]=1;
	while(T--){
		cin >> N;
		cout << solve(N) << "\n";
	}
}