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
const int MAX = 1e3 + 1;
const ll INF = 1e9;

int D, P;
ll limit;
queue<ll> Q;
unordered_map<int, bool> inQueue;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> D >> P;
	rep(i, 2, 10) { Q.push(i); inQueue[i] = 1;}
	if(P == 0){
		cout << 1;
		return 0;
	}
	if(P == 1){
		cout << 9;
		return 0;
	}
	if(P == 2){
		cout << 81;
		return 0;
	}
	limit = (ll) pow(10, D);
	rep(_, 0, P - 1) {
		int sz = Q.size();
		inQueue.clear();
		rep(__, 0, sz){
			ll u = Q.front(); Q.pop();
			rep(i, 2, 10) {
				ll v = i * u;
				if(v < limit && !inQueue[v]) {
					Q.push(v);
					inQueue[v] = 1;
				}
			}
		}
	}
	ll ans = -1;
	while(!Q.empty()) {
		ans = max(ans, Q.front());
		Q.pop();
	}
	cout << ans;
}
	
