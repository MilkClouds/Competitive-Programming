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

const int MAX = 1e5 + 5;
struct liquid{
    ll d, p, l;
    bool operator < (const liquid& o) const {
        if(d != o.d) return d < o.d;
        return p > o.p;
    }
} liquids[MAX];
ll N, M, d, p, l, g[MAX], L[MAX], S[MAX], E[MAX], j_to_flav[MAX], tree[MAX], tree2[MAX];
set<ll> fl;

void update(int i, ll x){
    for(int j = i; j < MAX; j += j & -j) tree2[j] += x * i;
    for(; i < MAX; i += i & -i) tree[i] += x;
}
ll query1(int i){
    ll ret = 0;
    for(; i; i ^= i & -i) ret += tree[i];
    return ret;
}
ll query2(int i){
    ll ret = 0;
    for(; i; i ^= i & -i) ret += tree2[i];
    return ret;
}
int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cin >> N >> M;
    rep(i, 0, N) {
        cin >> d >> p >> l;
        liquids[i] = {d, p, l};
        fl.insert(d);
    }
    sort(liquids, liquids + N);
    ll j = 1;
    rep(i, 0, N){
        while(i < N - 1 && liquids[i].d == liquids[i + 1].d) i++;
        j_to_flav[j++] = liquids[i].d;
    }
    rep(i, 0, M){
        cin >> g[i] >> L[i];
    }
    fill(S, S + M, 0);
    fill(E, E + M, fl.size());
    while(1) {
        vector<vector<int>> flavour(fl.size() + 1, vector<int>());
        ll cnt = 0;
        rep(i, 0, M){
            if(E[i] <= S[i]) continue;
            flavour[S[i] + E[i] + 1 >> 1].pb(i);
            cnt++;
        }
        if(cnt == 0) break;
        ll j = fl.size();
        fill(tree, tree + MAX, 0);
        fill(tree2, tree2 + MAX, 0);
        rep2(i, 0, N) {
            while(i > 0 && liquids[i].d == liquids[i - 1].d) {
                update(liquids[i].p, liquids[i].l);
                i--;
            }
            update(liquids[i].p, liquids[i].l);
            for(auto man: flavour[j]){
                int lo = 0, hi = MAX;
                while(lo + 1 < hi) {
                    int m = lo + hi >> 1;
                    if(query1(m) >= L[man]) hi = m;
                    else lo = m;
                }
                if(hi == MAX) {
                    E[man] = j - 1;
                    continue;
                }
                if((L[man] - query1(lo)) * hi + query2(lo) <= g[man]) S[man] = j;
                else E[man] = j - 1;
            }
            j--;
        }
    }
    rep(i, 0, M) {
        cout << (S[i] == 0 ? -1 : j_to_flav[S[i]]) << "\n";
    }
}

