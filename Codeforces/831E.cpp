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
using ll = long long;
using tl = tuple<ll, ll, ll, ll>;
using pl = pair<ll, ll>;
using pi = pair<int, int>;
using ld = long double;

const int MAX = 1e5 + 100, INF = 1e9;
int N, A[MAX], tree[MAX], cur = -1;
set<int> S;
vector<int> B[MAX];
ll ans;
int query(int i){
    int ret = 0; i++;
    for(; i; i ^= i & -i) ret += tree[i];
    return ret;
}
void update(int i, int x){
    i++;
    for(; i <= N; i += i & -i) tree[i] += x;
}
int dist(int u, int v){
    if(u <= v) return query(v) - query(u);
    else return query(N - 1) - query(u) + query(v);
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N;
    rep(i, 0, N) {
        cin >> A[i];
        B[A[i]].pb(i); S.insert(A[i]);
    }
    rep(i, 0, N) update(i, 1);
    for(auto i: S) {
        auto pos = lower_bound(all(B[i]), cur);
        for(auto p = pos; p != B[i].end(); p++){
            ans += dist(cur, *p);
            update(*p, -1);
            cur = *p;
        }
        if(pos != B[i].begin()){
            ans += dist(cur, N - 1); cur = -1;
            for(auto p = B[i].begin(); p != pos; p++){
                ans += dist(cur, *p);
                update(*p, -1);
                cur = *p;
            }
        }
    }
    cout << ans;
}