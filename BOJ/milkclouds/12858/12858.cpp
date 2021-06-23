# pragma GCC optimize ("O3")
# pragma GCC optimize ("Ofast")
# pragma GCC optimize ("unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
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

ll gcd(ll a, ll b){
    if(a < b) swap(a, b);
    if(b == -1) return a;
    if(a % b == 0) return b;
    return gcd(b, a % b);
}

class TreeNode {
public:
    bool flag = 0;
    int node, l, r;
    ll value, lazy;
    TreeNode* left, right;
    TreeNode(){}
    TreeNode(int node, int l, int r, vector<ll>& v){
        value = v[node];
        left = right = nullptr;
        if(r - l == 1) return;
        int m = l + r >> 1;
        left = new TreeNode(node * 2, l, m, v);
        right = new TreeNode(node * 2 + 1, m, r, v);
    }
    void push(){
        if(lazy == 0) return;
        for(auto child: {left, right}){
            if(child != nullptr) child.lazy += lazy;
        }
        lazy = 0;
    }
    void update(int s, int e, int x){
        push();
        if(s <= l && r <= e){
            lazy += x;
            push();
            return;
        }
        if(e <= l || r <= s) return;
        for(auto child: {left, right}){
            child.update(s, e, x);
        }
    }
    ll query(int s, int e){
        push();
        if(s <= l && r <= e) return value;
        if(e <= l || r <= s) return 0;
        ll ret = 0;
        for(auto child: {left, right}){
            ret += child.query(s, e);
        }
        return ret;
    }
};

int N, c, l, r;
vector<ll> A;
int main() {
    cin.tie(0) -> sync_with_stdio(false); cout.tie(0);
    cin >> N;
    A.assign(N);
    rep(i, 0, N) cin >> A[i];
    TreeNode root = new TreeNode(1, 0, N, A);
    cin >> M;
    while(M--){
        cin >> c >> l >> r;
        if(c == 0) cout << root.query(l, r) << "\n";
        else{
            root.update(l, r, c);
        }
    }
}
