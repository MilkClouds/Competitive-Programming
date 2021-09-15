#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
#define pb push_back
 
using namespace std;
typedef long long ll;
const int MAX = 2e5 + 1;

struct P {
    ll i, w, h;
    P(){P(0,0,0);}
    P(ll i, ll w, ll h):i(i),w(w),h(h){}
    bool operator <(P o) {
    	if(w != o.w) return w < o.w;
    	return h < o.h;
    }
} A[MAX];

ll TC, N, w[MAX], h[MAX], ans[MAX];
vector<pair<ll, ll> > v;
pair<ll ,ll> min_ele[MAX];

int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
	cin >> TC;
	while(TC--){
		cin >> N;
		rep(i, 0, N) {
			cin >> w[i] >> h[i];
			if(w[i] < h[i]) swap(w[i], h[i]);
			A[i] = P(i, w[i], h[i]);
		}
		sort(A, A + N);
		v.clear(); v.pb({A[0].w, A[0].i});
		rep(i, 1, N) if(A[i].w != A[i - 1].w) v.pb({A[i].w, A[i].i});
		min_ele[0] = {h[v[0].second], v[0].second};
		rep(i, 1, v.size()){
			if(min_ele[i - 1].first > h[v[i].second]) min_ele[i] = {h[v[i].second], v[i].second};
			else min_ele[i] = min_ele[i - 1];
		}
		fill(ans, ans + N , -1);
		rep(i, 0, N){
			auto pos = lower_bound(v.begin(), v.end(), pair<ll, ll>({w[i], 0}));
			if(pos == v.begin()) continue;
			pos--;
			if(min_ele[pos - v.begin()].first >= h[i]) continue;
			ans[i] = min_ele[pos - v.begin()].second + 1;
			/*
			for(ll j: v){
				if(A[j].w >= w[i]) break;
				if(A[j].h < h[i]) ans[i] = A[j].i;
			}*/
		}
		rep(i, 0, N) cout << ans[i] << " ";
		cout << "\n";
	}
}