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

ll sz[3], A[3][51], T;
bool f(ll x){
	for(;x;x/=10)if(x%10 != 5 && x%10 != 8) return 0;
	return 1;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> T;
	while(T--){
		ll ans = 0;
		rep(i, 0, 3){
			cin >> sz[i];
			rep(j, 0, sz[i]) cin >> A[i][j];
		}
		unordered_set<ll> S;
		rep(i, 0, sz[0]) rep(j, 0, sz[1]) rep(k, 0, sz[2]) S.insert(A[0][i] + A[1][j] + A[2][k]);
		for(auto i: S) ans += f(i);
		cout << ans << "\n";
	}
}