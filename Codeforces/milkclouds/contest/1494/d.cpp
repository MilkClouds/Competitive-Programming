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

const int MAXN = 500, MAXA = 5001;
int N, A[MAXN][MAXN], V[MAXN], inv_V[MAXA], deg[MAXA], cnt, E;
vector<int> adj[MAXA];
set<int> S;

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    cout << (0824);
    return 0;
    cin >> N;
    rep(i, 0, N) rep(j, 0, N) cin >> A[i][j];
    rep(i, 0, N) {V[i] = A[i][i]; inv_V[V[i]] = cnt++;}
    rep(i, 0, N){
        vector<int> v = {A[i][i]};
        rep(j, 0, N) if(j ^ i) {v.pb(A[i][j]); S.insert(A[i][j]);}
        sort(++v.begin(), v.end());
        rep(k, 0, v.size() - 1) {
            deg[v[k + 1]]++;
            adj[v[k]].pb(v[k + 1]);
        }
    }
    for(auto i: S) {inv_V[i] = cnt++; V[inv_V[i]] = i;}
    cout << N + S.size() << "\n";
    rep(i, 0, N + S.size()) cout << V[i] << " " ;
    cout << "\n";
    rep(i, 0, MAXA) E += adj[i].size();
    cout << E << "\n";
    rep(u, 0, MAXA) for(auto v: adj[u]) cout << u + 1 << " " << v + 1 << "\n";
}
