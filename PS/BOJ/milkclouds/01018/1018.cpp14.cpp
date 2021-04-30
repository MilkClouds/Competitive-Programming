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

string R = "WB", S[51];
ll N, M, ans = 1e9;
ll query(ll u, ll v){
	ll a = 0, b = 0;
	rep(i, u, u + 8) rep(j, v, v + 8)
		S[i][j]==R[(i + j) % 2] ? a++ : b++;
	return min(a, b);
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N >> M;
	rep(i, 0, N) cin >> S[i];
	rep(i, 0, N - 7) rep(j, 0, M - 7) ans = min(ans, query(i, j));
	cout << ans << endl;
}