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

const ll MAXN = 1e5 + 10, MAX = 1e18 + 10000;
int TC, N, M;
pl A[MAXN];
ll x;

struct Node{
    int l, r;
    ll v;
    Node(){ l = r = -1; v = 0; }
};
struct SegTree{
    vector<Node> nd;
    ll N;
    int pv = 1;
    SegTree(ll N, ll K): N(N), nd(K) {}
    void update(ll x, ll v){
        update(0, 0, N, x, v);
    }
    ll query(ll l, ll r){
        return query(0, 0, N, l, r);
    }
private:
    void update(int node, ll s, ll e, ll x, ll v){
        if(s == e){
            nd[node].v += v; return;
        }
        ll m = s + e >> 1;
        if(x <= m){
            if(nd[node].l == -1) nd[node].l = pv++;
            update(nd[node].l, s, m, x, v);
        }else{
            if(nd[node].r == -1) nd[node].r = pv++;
            update(nd[node].r, m+1, e, x, v);
        }
        ll t1 = nd[node].l != -1 ? nd[nd[node].l].v : 0;
        ll t2 = nd[node].r != -1 ? nd[nd[node].r].v : 0;
        nd[node].v = t1 + t2;
    }

    ll query(int node, ll s, ll e, ll l, ll r){
        if(node == -1) return 0;
        if(r < s || e < l) return 0;
        if(l <= s && e <= r) return nd[node].v;
        ll m = s + e >> 1;
        return query(nd[node].l, s, m, l, r) + query(nd[node].r, m+1, e, l, r);
    }
};
set<ll> events;
void remove(SegTree& tree, ll x){
    tree.update(x, -1);
    tree.update(x + 1, 1);
    if(tree.query(0, x - 1) > 0) events.insert(x - 1);
    if(tree.query(0, x) == 0) events.erase(x);
    if(tree.query(0, x + 1) > 0) events.insert(x + 1);
}
void solve(){
    cin >> N >> M;
    SegTree tree(MAX, (M + N) * 60 * 4);
    events.clear();
    rep(i, 0, N) {
        cin >> A[i].x >> A[i].y;
        tree.update(A[i].x, 1);
        tree.update(A[i].y + 1, -1);
        events.insert(A[i].x);
        events.insert(A[i].y);
    }
    rep(i, 0, M){
        cin >> x;
        if(tree.query(0, x)){
            cout << x << " ";
            remove(tree, x);
            continue;
        }
        auto pos = events.lower_bound(x);
        auto l = pos, r = pos;
        if(pos == events.begin()){
        } else if (pos == events.end()){
            pos--;
        } else{
            l--;
            if(abs(*l - x) <= abs(*r - x)) pos = l;
            else pos = r;
        }
        cout << *pos << " ";
        remove(tree, *pos);
    }
    cout << "\n";
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> TC;
    rep(tc, 0, TC){
        cout << "Case #" << tc + 1 << ": "; solve();
    }
}
