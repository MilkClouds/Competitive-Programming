#include <bits/stdc++.h>
#define rep(a,b,c) for(ll a = b; a < c; a++)
#define rep2(a,b,c) for(ll a = c - 1; a >=b; a--)
#define all(x) (x).begin(), (x).end()
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;

const ll MAX = 3e5 + 3, INF = 1e9;

ll N, p[MAX], dp[MAX], l[MAX], r[MAX], ans[MAX];

struct segTree
{
    ll n;
    bool mx;
    vector<ll> t;

    void fix(ll v)
    {
        t[v] = (mx ? max(t[v * 2 + 1], t[v * 2 + 2]) : min(t[v * 2 + 1], t[v * 2 + 2]));
    }

    void build(ll v, ll l, ll r)
    {
        if (l == r - 1)
            t[v] = (mx ? -INF : INF);
        else
        {
            ll m = (l + r) / 2;
            build(v * 2 + 1, l, m);
            build(v * 2 + 2, m, r);
            fix(v);
        }
    }

    void upd(ll v, ll l, ll r, ll pos, ll val)
    {
        if (l == r - 1)
            t[v] = (mx ? max(t[v], val) : min(t[v], val));
        else
        {
            ll m = (l + r) / 2;
            if (pos < m)
                upd(v * 2 + 1, l, m, pos, val);
            else
                upd(v * 2 + 2, m, r, pos, val);
            fix(v);
        }
    }

    ll get(ll v, ll l, ll r, ll L, ll R)
    {
        if (L >= R)
            return (mx ? -INF : INF);
        if (l == L && r == R)
            return t[v];
        ll m = (l + r) / 2;
        ll lf = get(v * 2 + 1, l, m, L, min(R, m));
        ll rg = get(v * 2 + 2, m, r, max(m, L), R);
        return (mx ? max(lf, rg) : min(lf, rg));
    }

    void upd(ll pos, ll val)
    {
        upd(0, 0, n, pos, val);
    }

    ll get(ll L, ll R)
    {
        return get(0, 0, n, L, R);
    }

    void build()
    {
        return build(0, 0, n);
    }

    segTree() {};
    segTree(ll n, bool mx) : n(n), mx(mx)
    {
        t.resize(4 * n);
    }
};


void solve() {
	cin >> N;
	rep(i, 0, N) cin >> p[i + 1];
	fill(dp, dp + N + 1, -INF);
    fill(ans, ans + N + 1, -2);
    segTree minTree(N + 1, false), maxTree(N + 1, true);
    minTree.build(); maxTree.build();
    minTree.upd(0, 0);
    dp[0] = 0;
    rep(i, 1, N + 1) {
        l[i] = max((ll)1, i - p[i]);
        r[i] = min(N, i + p[i]);
        maxTree.upd(i, r[i]);
    }
    rep(i, 1, N + 1) {
        ll m = minTree.get(l[i] - 1, N + 1);
        if (m != INF) {
            ll nval = max(i - 1, maxTree.get(m + 1, i - 1 + 1));
            if (nval > dp[i]) {
                dp[i] = nval;
                ans[i] = m;
            }
        }
        if (dp[i - 1] >= i && max(dp[i - 1], r[i]) > dp[i]) {
            dp[i] = max(dp[i - 1], r[i]);
            ans[i] = -1;
        }
        if (dp[i - 1] > dp[i]) dp[i] = dp[i - 1];
        minTree.upd(dp[i], i);
    }
    if (dp[N] != N) { cout << "NO\n"; return; }
    cout << "YES\n";
    ll chk = N+1;
    string s;
    rep2(i, 1, N + 1) {
        //cout << ans[i] << " " << i <<" " <<chk<< endl;
        if (chk < i) { s += "R"; continue; }
        if (ans[i] <0) s += "R";
        if (ans[i]>=0) {
            s += "L";
            chk = ans[i];
        }
    }
    reverse(all(s));
    cout << s << "\n";
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	ll TC;
	cin >> TC;
	while (TC--) solve();
}
