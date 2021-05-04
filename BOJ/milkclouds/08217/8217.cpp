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
#define x first
#define y second
using namespace std;
using pi = pair<int, int>;
using ld = long double;

const int MAX = 3e5 + 1;
int N, M, o[MAX], p[MAX], Q, l[MAX], r[MAX], a[MAX], ll[MAX], rr[MAX];
vector<int> rev_o[MAX];
__int128 tree[MAX];
void update(int i, int x){
    for(;i <= M; i += i & -i) tree[i] += x;
}
__int128 query(int i){
    __int128 ret = 0;
    for(;i; i ^= i & -i) ret += tree[i];
    return ret;
}
__int128 sum(int i){
    __int128 ans = 0;
    for(auto j: rev_o[i]){
        ans += query(j + 1);
    }
    return ans;
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M;
    rep(i, 0, M) {
        cin >> o[i];
        rev_o[o[i] - 1].pb(i);
    }
    rep(i, 0, N) cin >> p[i];
    cin >> Q;
    rep(i, 0, Q){
        cin >> l[i] >> r[i] >> a[i];
    }
    fill(ll, ll + N, 0);
    fill(rr, rr + N, Q + 1);
    while(1){
        vector<vector<int>> time(Q + 1, vector<int>());
        int cnt = 0;
        rep(i, 0, N){
            if(rr[i] - ll[i] == 1) continue;
            time[ll[i] + rr[i] >> 1].pb(i);
            cnt++;
        }
        if(cnt == 0) break;
        fill(tree, tree + M + 1, 0);
        rep(u, 0, Q){
            if(l[u] <= r[u]){
                update(l[u], a[u]);
                update(r[u] + 1, -a[u]);
            } else {
                update(l[u], a[u]);
                update(1, a[u]);
                update(r[u] + 1, -a[u]);
            }
            for(auto i: time[u + 1]){
                if(sum(i) >= p[i]) rr[i] = u + 1;
                else ll[i] = u + 1;
            }
        }
    }
    rep(i, 0, N) cout << (rr[i] <= Q ? to_string(rr[i]) : "NIE") << "\n";
}
