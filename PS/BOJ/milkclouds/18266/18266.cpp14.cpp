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

const int MAX = 5e4;

ll N, L, W[MAX], X[MAX], D[MAX], tot, ans, cur, to_right[MAX], to_left[MAX], rsz, lsz;
vector<pi> Weights;
map<ll, vector<pi> > events;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N >> L;
	rep(i, 0, N){
		cin >> W[i] >> X[i] >> D[i]; tot += W[i];
		Weights.pb({X[i], W[i]});

		if(D[i] == 1) events[L - X[i]].pb({i, 1});
		else events[X[i]].pb({i, -1});

		if(D[i] == 1) to_right[rsz++] = X[i];
		else to_left[lsz++] = X[i];
	}
	sort(to_left, to_left + lsz);
	sort(to_right, to_right + rsz);
	sort(Weights.begin(), Weights.end());
	ll lo = 0, hi = N - 1;
	for(auto it = events.begin(); it != events.end(); it++){
		auto& v = it -> second;
		rep(i, 0, v.size()){
			if(v[i].y == 1)
				cur += Weights[hi--].y;
			else 
				cur += Weights[lo++].y;
		}
		if(cur >= tot / 2 + (tot % 2)){
			ll time = it -> first;
			rep(i, 0, rsz){
				ans += upper_bound(to_left, to_left + lsz, to_right[i] + time * 2) - lower_bound(to_left, to_left + lsz, to_right[i]);
			}
			cout << ans << endl;
			return 0;
		}
	}
}