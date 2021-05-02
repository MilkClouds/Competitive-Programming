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
const ll INF = 3e9, MOD = 1e9 + 7, MAX = 15e4;

int N, B[51], ans, ml;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N;
	rep(i, 0, N) cin >> B[i];
	rep(i, 0, N){
		for(int t = B[i], c = 0; t; t >>= 1, c++){
			ans += t & 1;
			ml = max(ml, c);
		}
	}
	cout << ans + ml;
}
	
