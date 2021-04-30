#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i < (b); i++)
#define rep2(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define x first
#define y second
using namespace std;
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;


const ll MOD = 1e9 + 7;
const int MAX = 200001;

struct modint{
    ll v; explicit operator ll() const {return v;}
    modint(ll v): v((MOD + v) % MOD){}
    modint(): modint(0){}
    modint operator +(modint b){return modint(v + b.v);}
    modint operator -(modint b){return modint(v - b.v);}
    modint operator *(modint b){return modint(v * b.v);}
    modint operator *=(modint b){v = v * b.v % MOD; return *this;}
};
struct T{
    vector<modint> v;
    T(): v(11, 0){}
    T(vector<modint> v): v(v){}
    T operator +(T b){
        vector<modint> vv(11, 0);
        rep(i, 0, 11) vv[i] = v[i] + b.v[i];
        return vv;
    }
    T operator *(modint b){
        vector<modint> vv(11, 0);
        rep(i, 0, 11) vv[i] = v[i] * b;
        return vv;
    }
    T operator +=(T b){
        rep(i, 0, 11) v[i] = v[i] + b.v[i];
        return *this;
    }
    modint& operator [](int i){
        return v[i];
    }
};

vector<pi> v;
vector<int> y;

ll N, K;


modint cum[11][11];

T adv(T p) {
  for (int i = K; i >= 0; --i) for (int j = i; j <= K; ++j)
    cum[i][j] = (i == j ? p[i] : cum[i][j-1]+cum[i+1][j]);
  T res; for (int i = 0; i <= K; ++i) res[i] = cum[0][i];
  return res;
}


T tree[1<<18];
modint lazy[1<<18];

void push(int node, int l, int r){
    if(lazy[node].v == 1) return;
    tree[node] = tree[node] * lazy[node];
    if(l ^ r){
        for(auto v: {node * 2, node * 2 + 1}){
            lazy[v] *= lazy[node];
        }
    }
    lazy[node] = 1;
}

void mul(int node, int l, int r, ll x){
    push(node, l, r);
    if(x > r) return;
    if(x <= l){
        lazy[node] = 2;
        push(node, l, r);
        return;
    }
    int m = l + r >> 1;
    mul(node * 2, l, m, x);
    mul(node * 2 + 1, m + 1, r, x);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(int node, int l, int r, int x, T v){
    push(node, l, r);
    if(r < x || x < l) return;
    if(l == r){
        tree[node] = tree[node] + v;
        return;
    }
    int m = l + r >> 1;
    update(node * 2, l, m, x, v);
    update(node * 2 + 1, m + 1, r, x, v);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void query(int node, int l, int r, int s, int e, T& ret){
    push(node, l, r);
    if(r < s || e < l) return;
    if(s <= l && r <= e) {
        ret += tree[node];
        return;
    }
    int m = l + r >> 1;
    query(node * 2, l, m, s, e, ret);
    query(node * 2 + 1, m + 1, r, s, e, ret);
}

void add(int a, int b){
    auto t1 = lower_bound(all(y), a) - y.begin() - 1;
    auto t2 = lower_bound(all(y), b) - y.begin();
    T A = T(); query(1, 0, N, 0, t1, A); A = adv(A);
    T B = T(); query(1, 0, N, t1 + 1, t2, B);
    update(1, 0, N, t2, A + B);
    mul(1, 0, N, t2 + 1);
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N; K = 1;
    v.resize(N); y.assign(N + 1, 0);
    rep(i, 0, N) {
        cin >> v[i].x >> v[i].y;
        y[i + 1] = v[i].y;
    }
    sort(all(v)); sort(all(y));
    T tmp = T(); tmp.v[0] = 1;
    update(1, 0, N, 0, tmp);
    for(auto t: v) add(t.x, t.y);
    T ret = T();
    query(1, 0, N, 0, N, ret);
    cout << ret.v[K].v << endl;
}
