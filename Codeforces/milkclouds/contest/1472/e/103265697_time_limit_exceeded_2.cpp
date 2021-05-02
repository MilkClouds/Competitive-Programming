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
vector<ll> v;

int main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
	cin >> TC;
	while(TC--){
		cin >> N;
		rep(i, 0, N) {
			cin >> w[i] >> h[i];
			if(w[i] < h[i]) swap(w[i], h[i]);
			A[i] = P(i + 1, w[i], h[i]);
		}
		sort(A, A + N);
		v.clear(); v.pb(0);
		rep(i, 1, N) if(A[i].w != A[i - 1].w) v.pb(i);
		fill(ans, ans + N , -1);
		rep(i, 0, N){
			for(ll j: v){
				if(A[j].w >= w[i]) break;
				if(A[j].h < h[i]) ans[i] = A[j].i;
			}
		}
		rep(i, 0, N) cout << ans[i] << " ";
		cout << "\n";
	}
}