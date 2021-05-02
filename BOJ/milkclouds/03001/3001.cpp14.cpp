# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a=b;a<c;a++)
#define rep2(a,b,c) for(ll a=b;a>c;a--)
#define pb push_back
#define x first
#define y second
#define all(x) x.begin(), x.end()
using namespace std;
using ll=long long;
using ti=tuple<ll,ll,ll>;
using pi=pair<ll,ll>;
const ll INF = 1e9;
const int MAX = 1e5 + 1;

ll dp[16][136],A,B,S;

ti f(ll a){
	ll cnt = 0, rev = 0;
	while(a >= 10){ rev += pow(10, cnt) * (a % 10); a /= 10; cnt++;}
	return ti(cnt, a, rev);
}
// 1~a 까지 수 중 자리수 합이 S인 수의 개수
ll get(ll a,ll S){
	ll p,q,r;
	tie(p, q, r) = f(a);
	if(p == 0){
		return S <= a;
	}
	ll ret = dp[p][S];
	rep(k,1,q) {
		if(S - k < 0) break;
		ret += dp[p][S - k];
	}
	if(S - q >= 0)	ret += get(r, S - q);
	return ret;
}
ll getsum(ll a){
	ll ret = 0;
	while(a){ret += a%10; a/=10;}
	return ret;
}
ll getmin(ll S,ll E,ll N){
	ll m = S + E >> 1;
	if(getsum(S)==N)return S;
	if(get(m,N) - get(S - 1, N)) return getmin(S, m, N);
	return getmin(m + 1, E, N);
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> A >> B >> S;
	rep(i,0,10) dp[1][i] = 1;
	// dp[i][j] : 1~i자리, 합 j 수 개수
	rep(i,2,16) rep(j,0,136) {
		rep(k,0,10) dp[i][j] += dp[i - 1][j - k];
	}
	cout << get(B, S) - get(A - 1, S) << endl;
	cout << getmin(A, B, S) << endl;
}
	