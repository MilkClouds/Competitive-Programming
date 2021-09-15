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

const int MAX = 1e5 + 1, INF = 1e9 + 11;
int N, A[MAX], u, v, cnt, dp[MAX];
vector<int> adj[MAX];

class TreeNode {
public:
    int node, l, r;
    ll value = 0, lazy = 0;
    TreeNode *left = nullptr, *right = nullptr;
    TreeNode(): TreeNode(0, 0, INF) {}
    TreeNode(int node, int l, int r): node(node), l(l), r(r) {}
    TreeNode(int node, int l, int r, vector<ll>& v): node(node), l(l), r(r) {
        if(r - l == 1){
            left = right = nullptr;
            value = v[node];
            return;
        }
        int m = l + r >> 1;
        left = new TreeNode(lnode(), l, m, v);
        right = new TreeNode(rnode(), m, r, v);
        value = left -> value + right -> value;
    }
    void push(){
        if(lazy == 0) return;
        value += lazy * (r - l);
        if(r - l > 1) {
            int m = l + r >> 1;
            if(left == nullptr) left = new TreeNode(lnode(), l, m);
            if(right == nullptr) right = new TreeNode(rnode(), m, r);
            for(auto& child: {left, right}){
                child -> lazy += lazy;
            }
        }
        lazy = 0;
    }
    ll update(int s, int e, ll x){
        push();
        if(e <= l || r <= s) return value;
        // cout << l << " " << r << " " << s << " " << e << " " << x << endl;
        if(s <= l && r <= e){
            lazy += x;
            push();
            return value;
        }
        int m = l + r >> 1;
        if(left == nullptr) left = new TreeNode(lnode(), l, m);
        if(right == nullptr) right = new TreeNode(rnode(), m, r);
        return value = left -> update(s, e, x) + right -> update(s, e, x);
    }
    ll query(int s, int e){
        if(e <= l || r <= s) return 0;
        push();
        // cout << l << " " << r << " " << s << " " << e << " " << value << endl;
        if(s <= l && r <= e) return value;
        ll ret = 0;
        for(auto& child: {left, right}){
            if(child != nullptr) ret += child -> query(s, e);
        }
        return ret;
    }
private:
    int lnode(){return node * 2 + 1;}
    int rnode(){return node * 2 + 2;}
} root;

int median(){
    int l = 0, r = INF;
    while(l < r){
        int m = l + r >> 1;
        //cout << m << " " << root.query(0, m) << " " << cnt << endl;
        if(root.query(0, m + 1) < cnt / 2 + 1) l = m + 1;
        else r = m;
    }
    if(cnt & 1) return l;
    int t = l;
    l = 0;
    while(l < r){
        int m = l + r >> 1;
        if(root.query(0, m + 1) < cnt / 2) l = m + 1;
        else r = m;
    }
    return (l + t) / 2;
}
int dfs(int u, int par, int player){
    root.update(A[u], A[u] + 1, 1); cnt++;
    set<int> S;
    for(auto v: adj[u]){
        if(v == par) continue;
        S.insert(dfs(v, u, player ^ 1)); 
    }
    if(S.size() == 0){
        dp[u] = median();
    }
    root.update(A[u], A[u] + 1, -1); cnt--;
    if(S.empty()) return dp[u];
    if(player == 0) return *S.rbegin();
    return *S.begin();
}
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    rep(i, 1, N){
        cin >> u >> v; u--; v--;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    cout << dfs(0, -1, 0) << endl;
}
