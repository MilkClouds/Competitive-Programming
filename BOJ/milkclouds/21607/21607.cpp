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

const int MOD = 100003, MAX = 5e5;
int N, Q, A[MAX], t, l, r, x, B[MOD][20], C[MOD][20];
pi tree[MAX * 4];

pi operator + (pi a, pi b){
    return {a.x + b.x, b.y + a.y};
}

int f(int x){
    return ((ll) 2 * x * x - 1 + MOD) % MOD;
}
int g(int x){
    return ((ll) 4 * x * x * x - 3 * x + MOD) % MOD;
}

int evaluate(int i, pi o){
    int cnt = 0;
    while(o.x){
        if(o.x & 1){
            i = B[i][cnt];
        }
        o.x >>= 1;
        cnt++;
    }
    cnt = 0;
    while(o.y){
        if(o.y & 1){
            i = C[i][cnt];
        }
        o.y >>= 1;
        cnt++;
    }
    return i;
}

void update(int node, int l, int r, int s, int e, int t){
    if(r <= s || e <= l) return;
    if(s <= l && r <= e){
        if(t == 1) tree[node].x++;
        else tree[node].y++;
        return;
    }
    int m = l + r >> 1;
    update(node * 2, l, m, s, e, t);
    update(node * 2 + 1, m, r, s, e, t);
}

pi query(int node, int l, int r, int x){
    if(l <= x && x < r){
        if(r - l == 1) return tree[node];
        int m = l + r >> 1;
        return query(node * 2, l, m, x) + query(node * 2 + 1, m, r, x) + tree[node];
    }
    return {0, 0};
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> Q;
    rep(i, 0, MOD) B[i][0] = f(i);
    rep(i, 0, MOD) C[i][0] = g(i);
    rep(j, 1, 19){
        rep(i, 0, MOD) B[i][j] = B[B[i][j - 1]][j - 1];
        rep(i, 0, MOD) C[i][j] = C[C[i][j - 1]][j - 1];
    }
    rep(i, 0, N) cin >> A[i];
    while(Q--){
        cin >> t;
        if(t == 3){
            cin >> x;
            cout << evaluate(A[x - 1], query(1, 0, N, x - 1)) << "\n";
        } else {
            cin >> l >> r;
            update(1, 0, N, l - 1, r, t);
        }
    }
}
