# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define em emplace
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define x first
#define y second
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;
using pl = pair<ll, ll>;
using tl = tuple<ll, ll, ll>;

const int MAX = 1e5 + 10;
int N, K, A[MAX], pre[MAX][205], S[MAX];
ll dp[MAX][2];
vector<int> ans = {-1};

struct CHT{
	ll a[MAX], b[MAX], c[MAX];
	int pv, top;

	void init(){
		pv = top = 0;
	}

	ll f(ll idx, ll x){
		return a[idx]*x + b[idx];
	}

	void insert(ll aa, ll bb, ll cc){
		if(top >= 1 && aa == a[top-1]){
			c[top-1] = cc; return;
		}
		while(top >= 2 && (b[top-1] - b[top-2]) * (a[top-2] - aa) >= (bb - b[top-2]) * (a[top-2] - a[top-1])) top--;
		a[top] = aa;
		b[top] = bb;
		c[top] = cc;
		top++;
		if(pv >= top) pv = top - 1;
	}

	pl get(ll x){
		while(pv+1 < top && a[pv+1]*x + b[pv+1] > a[pv]*x + b[pv]) pv++;
		return {f(pv, x), c[pv]};
	}
} cht;

int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N >> K;
    rep(i, 1, N + 1) cin >> A[i], S[i] = S[i - 1] + A[i];
    rep(j, 1, K + 1) {
        cht.init();
        cht.insert(0, 0, 0);
        rep(i, 1, N + 1) {
            auto t = cht.get(S[i]);
            dp[i][j & 1] = t.x;
            pre[i][j] = t.y;
            cht.insert(S[i], dp[i][j & 1 ^ 1] - 1LL * S[i] * S[i], i);
        }
    }
    int i = N;
    cout << dp[N][K & 1] << endl;
    rep2(j, 1, K + 1){
        ans.eb(pre[i][j]);
        i = pre[i][j];
    }
    sort(all(ans));
    rep(j, 1, K + 1){
        if(!ans[j]) ans[j] = 1;
        if(ans[j] <= ans[j - 1]) ans[j] = ans[j - 1] + 1;
    }
    rep(j, 1, K + 1) cout << ans[j] << " \n"[j == K];
}