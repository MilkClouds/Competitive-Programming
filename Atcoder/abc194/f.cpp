# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;

const ll MOD = 1e9 + 7;
const int MAX = 2e5 + 1;
ll K;
string N;

struct MI{
	ll v;
	MI(ll v): v(v % MOD) {if(v < 0) v += MOD;}
	MI():MI(0){}
	MI operator * (const ll& a){
		return MI(v * a);
	}
	MI& operator += (const MI& a){
		v = (v + a.v) % MOD;
		return *this;
	}
} dp[MAX][17], ans;
set<int> S;


void OUT(){
	rep(i, 0, N.size()){
		rep(j, 1, 17) cout << dp[i + 1][j].v << " " ;
		cout << endl;
	}
}
int cti(char c){
	if(c <= '9') return c - '0';
	return c - 'A' + 10;
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cin >> N >> K;
	dp[1][1] += max(0, cti(N[0]) - 1);
	rep(i, 1, N.size()){
		S.insert(cti(N[i - 1]));
		rep(j, 0, cti(N[i])){
			if(S.count(j)){
				dp[i + 1][S.size()] += 1;
			} else dp[i + 1][S.size() + 1] += 1;
		}
	}
	S.insert(cti(N[N.size() - 1]));
	if(S.size() == K) ans += 1;
	rep(i, 1, N.size()){
		dp[i + 1][1] += 15;
		rep(j, 1, 17){
			dp[i + 1][j] += dp[i][j] * j;
			dp[i + 1][j + 1] += dp[i][j] * (16 - j);
		}
	}
	ans += dp[N.size()][K];
	cout << ans.v;
}
